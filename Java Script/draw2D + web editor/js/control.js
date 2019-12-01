var randomColor = function (weight) {
    return colors[Math.floor(Math.random() * colors.length)][weight];
};

var NewSlide = function() {

    var canvas = new draw2d.Canvas("gfx_holder");

    // Override the standard ResizeHandle and add some fancy filter to the SVG element
    // We need the fraphael.js lib to apply the filter
    //
    var filter = canvas.paper.createFilter();
    filter.createShadow(1.7, 1.7, 2, 0.8, "#303030");
    filter.element.setAttribute("x", "-55%");
    filter.element.setAttribute("y", "-55%");
    filter.element.setAttribute("width", "400%");
    filter.element.setAttribute("height", "400%");

    draw2d.Configuration.factory = $.extend({}, draw2d.Configuration.factory, {

        createResizeHandle: function (owner, type) {
            var handle = new draw2d.ResizeHandle({
                owner: owner,
                type: type,
                width: 10,
                height: 10,
                radius: 4,
                bgColor: "#2196f3",
                stroke: 0
            });

            handle.useGradient = false;
            handle._origShow = handle.show;
            // override the standard "show" method to apply the filter to the create raphael element
            //
            handle.show = function (canvas) {
                this._origShow(canvas);
                this.shape.filter(filter);
            }.bind(handle);

            return handle;
        },

        // @since 5.3.0
        createInputPort: function (relatedFigure) {
            var p = new draw2d.InputPort({
                bgColor: "#ff9100",
                stroke: 0
            });
            p.useGradient = false;
            return p;
        },
        // @since 5.3.0
        createOutputPort: function (relatedFigure) {
            var p = new draw2d.OutputPort({
                bgColor: "#ff9100",
                stroke: 0
            });
            p.useGradient = false;
            return p;
        },
        // @since 5.3.0
        createHybridPort: function (relatedFigure) {
            var p = new draw2d.HybridPort({
                bgColor: "#ff9100",
                stroke: 0
            });
            p.useGradient = false;
            return p;
        }
    });

    canvas.on("figure:add", function (emitter, event) {
        if (!(event.figure instanceof draw2d.Connection)) {
            event.figure.shape.filter(filter);
        }
    });

    canvas.installEditPolicy(new draw2d.policy.canvas.FadeoutDecorationPolicy());
    canvas.installEditPolicy(new draw2d.policy.connection.DragConnectionCreatePolicy({
        createConnection: function () {
            var conn = new draw2d.Connection({
                stroke: 5,
                color: randomColor("100"),
                router: null
            });

            conn.on("added", function (emitter) {
                emitter.toBack();
                emitter.shape[1].filter(filter);
            });
            return conn;
        }
    }));

    var add_oval = function(x, y, r = 0, s = 0) {
        canvas.add(new draw2d.shape.basic.Oval({
            radius: r,
            stroke: s,
            bgColor: randomColor("600")
        }), x, y);
    };
    
    var add_rectangle = function(x, y, r = 0, s = 0) {
        canvas.add(new draw2d.shape.basic.Rectangle({
            radius: r,
            stroke: s,
            bgColor: randomColor("600")
        }), x, y);
    }
    
    var add_msg = function(x, y, t) {
        var msg = new draw2d.shape.note.PostIt({
            text: t,
            x: x,
            y: y
        });
        canvas.add(msg);
    }


    canvas.add(new draw2d.shape.basic.Oval({
        stroke: 0,
        bgColor: randomColor("600")
    }), 100, 100);

    add_oval(150,150);

    canvas.add(new draw2d.shape.basic.Rectangle({
        radius: 2,
        stroke: 0,
        bgColor: randomColor("600")
    }), 120, 150);

    add_rectangle(400,400);

    /////////////////////////////////////////////////////////////////////
    // JUST ADD SOME DOCU ELEMENTS ON THE SCREEN
    /////////////////////////////////////////////////////////////////////
    var msg = new draw2d.shape.note.PostIt({
        text: "Select a shape to see CSS styled resize handles",
        x: 20,
        y: 20
    });
    // canvas.add(msg);

    add_msg(20,20,"test");

}



