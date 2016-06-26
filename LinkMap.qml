import QtQuick 2.0
import "Canvas.js" as CanvasLib

Canvas
{
    anchors.fill: parent

    Component.onCompleted: {
        requestPaint();
    }

    onPaint: draw();

    function draw()
    {
        var ctx = getContext("2d");
        CanvasLib.drawLine(ctx, 500, 500, 500, 200, '#ffffff')
    }
}
