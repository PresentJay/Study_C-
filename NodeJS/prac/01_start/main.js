var express = require('express');
var app = express();

var ejs = require('ejs');
app.set('views',__dirname + '/public');

app.get ('/', function(req, res){
    res.render('index.ejs');
});

app.listen(3000);