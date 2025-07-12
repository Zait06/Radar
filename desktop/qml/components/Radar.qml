import QtQml
import QtQuick

import desktop

Canvas {
    id: self

    enum RadioType {
        Full,
        Half
    }

    required property int radio
    property int type: Radar.Full
    property int _diameter: radio * 2
    property bool isFull: type === Radar.Full

    width: _diameter
    height: _diameter


    onPaint: {
        var ctx = getContext("2d")
        ctx.clearRect(0, 0, width, height)

        const endAngle = isFull ? 2 * Math.PI : Math.PI
        
        // Draw radio
        ctx.beginPath()
        ctx.fillStyle = "black"
        ctx.arc(radio, radio, radio, 0, endAngle, true)
        ctx.fill()

        // Draw concentric radios
        ctx.strokeStyle = "green";
        ctx.lineWidth = 2;
        for (var r = 50; r < radio; r += 50) {
            ctx.beginPath();
            ctx.arc(radio, radio, r, 0, endAngle, true);
            ctx.stroke();
        }

        // Draw cross lines
        const endLine = isFull ? _diameter : radio
        ctx.beginPath();
        ctx.moveTo(radio, 0);
        ctx.lineTo(radio, endLine);
        ctx.moveTo(0, radio);
        ctx.lineTo(endLine, radio);
        ctx.stroke();
    }

    // Sweep arm
    Rectangle {
        id: sweep
        height: 2
        width: self.radio
        color: "red"
        x: self.radio
        y: self.radio
        transformOrigin: Item.Left
        rotation: 360 - 60
    }
}