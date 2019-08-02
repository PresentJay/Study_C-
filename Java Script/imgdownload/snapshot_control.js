// 스크린샷 URL 저장 배열 *Jay
class Snapshot {
  constructor(videoId) {
    this.snapshots = [];
    this.videoId = document.getElementById(videoId);
  }

  remove(index) {
    this.snapshots.splice(index, 1);
  }


  dataURLtoBlob(dataurl) {
    var arr = dataurl.split(','),
      mime = arr[0].match(/:(.*?);/)[1],
      bstr = atob(arr[1]),
      n = bstr.length,
      u8arr = new Uint8Array(n);
    while (n--) {
      u8arr[n] = bstr.charCodeAt(n);
    }
    return new Blob([u8arr], {
      type: mime
    });
  }

  dataURItoBlob(dataURI) {
    var byteString = atob(dataURI.split(',')[1]);
    var mimeString = dataURI.split(',')[0].split(':')[1].split(';')[0]
    var ab = new ArrayBuffer(byteString.length);
    var ia = new Uint8Array(ab);
    for (var i = 0; i < byteString.length; i++) {
      ia[i] = byteString.charCodeAt(i);
    }

    var bb = new Blob([ab], {
      "type": mimeString
    });
    return bb;
  }


  //  스크린샷 함수
  shoot(iw, ih) {
    var video = this.videoId;
    var canvas = document.createElement('canvas');
    // var w = video.clientWidth;
    // var h = video.clientHeight;
    canvas.width = iw;
    canvas.height = ih;

    //ctx(canvas context) 객체에 canvas(canvas) 객체의 2d Context를 지정하고, canvas에 CONTENTS(video)를 그려놓는다. (image)
    var ctx = canvas.getContext('2d').drawImage(video, 0, 0, iw, ih);

    var image = new Image(iw, ih);
    var ctx = canvas.getContext("2d");
    image.onload = () => {
      ctx.drawImage(image, 0, 0, iw, ih);
    };
    image.src = canvas.toDataURL("image/png");


    this.snapshots.push(this.dataURItoBlob(image.src));
  }

  getLength() {
    return this.snapshots.length;
  }

  getLastitem() {
    return this.snapshots[this.snapshots.length - 1];
  }

  getVideoId() {
    return this.videoId;
  }

}