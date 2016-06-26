import QtQuick 2.0
import "UI.js" as UI
import "Canvas.js" as CanvasLib


Rectangle {
    property double inX: 0
    property double inY: 0
    property double inZ: 0

    property int h: 0
    property int w: 0

    property int a: 0

    property variant links: []

    signal agentPositionUpdated(string _id, double _x, double _y, double _z)

    id: rect

    color: "#1c1c1c"
    anchors.fill: parent

    Canvas{
        anchors.fill: parent

        id:canvas
        onPaint: draw()
    }


    Component.onCompleted: {
        h = parseInt(Settings.getValue("UI", "height"));
        w = parseInt(Settings.getValue("UI", "width"));

        inX = Settings.getValue("Playground", "x");
        inY = Settings.getValue("Playground", "y");
        inZ = Settings.getValue("Playground", "z");

        AppController.agentAdded.connect(onAgentAdded);
        AppController.clearLinks.connect(onClearLinks);
        AppController.addLink.connect(onAddLink);
        AppController.updateLinks.connect(onUpdateLinks);


        AppController.agentPositionUpdated.connect(onAgentPositionUpdated);

    }

    function test(_value)
    {
        a = _value;

        canvas.requestPaint();
    }


    function draw()
    {
        var ctx = canvas.getContext("2d");
        CanvasLib.clear(ctx, width, height);
        for(var i=0; i<links.length; i++)
        {
            var link = links[i];
            var pos1 = mapToMissionArea(link[0], link[1], 0);
            var pos2 = mapToMissionArea(link[3], link[4], 0);

            CanvasLib.drawLine(ctx, pos1.x, pos1.y, pos2.x, pos2.y);
        }
    }

    function onAgentAdded(_id, _x, _y, _z)
    {
        var agent = UI.createObject("Agent.qml", rect);
        var pos = mapToMissionArea(_x, _y, _z);

        agent.setId(_id);
        agent.setPosition(pos.x, pos.y);
    }

    function onAgentPositionUpdated(_id, _x, _y, _z)
    {
        var x = map(_x, 250, inX, 0.0, w);
        var y = map(_y, 250, inY, h, 0.0);

        agentPositionUpdated(_id, x, y, 0);
    }


    function mapToMissionArea(_x, _y, _z)
    {
        var pos = [];
        pos.x = map(_x, 250, inX, 0.0, w);
        pos.y = map(_y, 250, inY, h, 0.0);
        //pos.z = map(_z, 250, inZ, h, 0.0);

        return pos;
    }

    function map(_value, _inMin, _inMax, _outMin, _outMax)
    {
        return (_value-_inMin) * (_outMax-_outMin) / (_inMax-_inMin) + _outMin;
    }

    function onClearLinks()
    {
        links = [];
    }

    function onAddLink(_x1, _y1, _z1, _x2, _y2, _z2)
    {
        var link = [_x1, _y1, _z1, _x2, _y2, _z2];
        links.push(link);
    }

    function onUpdateLinks()
    {
        canvas.requestPaint();
    }

}