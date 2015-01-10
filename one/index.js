var gpio = require("pi-gpio");
var express = require('express');
var logger = require('morgan');
var bodyParser = require('body-parser');

var pin = 38;
var app = express();

app.use(logger('dev'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: false}));


function openPin(cb) {
    gpio.open(pin, "output", function (err) {        // Open pin for output
        if (err) {
            console.log("open pin " + pin + " error:" + err);
            cb(err);
        }
        else {
            cb();
        }
    });
}

function closePin(cb) {
    gpio.close(pin, function (err) {
        if (err) {
            console.log("close pin " + pin + " error:" + err);
            cb(err);
        }
        else {
            cb();
        }
    });

}

function upLight(req, res) {
    gpio.write(pin, 1, function (err) {
        return res.status(200).json({
            error: err
        });
    });
}
function downLight(req, res) {
    gpio.write(pin, 0, function (err) {
        return res.status(200).json({
            error: err
        });
    });
}
function timedLight(req, res) {
    var t = req.params.t;
    var it = parseInt(t);

    gpio.write(pin, 1, function (err) {
        setTimeout(function () {
            gpio.write(pin, 0, function (err) {
                if (err)console.log(err);
            });
        }, it);
        return res.status(200).json({
            error: err
        });
    });
}
function changePin(req, res) {
    var p = req.params.pin;
    var pi = parseInt(p);

    if (pi !== pin) {

        var old = pin;
        closePin(function (err) {
            if (err) {
                res.status(500).json({message: "change failed", error: err});
                return;
            }
            pin = pi;
            openPin(function (err) {
                if (err) {
                    pin = old;
                    return res.status(500).json({message: "change failed", error: err});
                } else {
                    return res.status(200).json({message: "change successful", error: err});
                }
            })
        });
    }
}

app.route('/up').all(upLight);
app.route('/down').all(downLight);
app.route('/time/:t').all(timedLight);
app.route('/to/:pin').all(changePin);

openPin(function () {
    console.log("initialized...");
});
app.listen(3001, function () {
    console.log('Express server listening on port 3001');
});
