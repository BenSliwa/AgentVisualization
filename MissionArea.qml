import QtQuick 2.0
import "UI.js" as UI



Rectangle {
    property double inX: 0
    property double inY: 0
    property double inZ: 0

    property int h: 0
    property int w: 0

    id: rect

    color: "#1c1c1c"
    anchors.fill: parent


    Component.onCompleted: {
        h = parseInt(Settings.getValue("UI", "height"));
        w = parseInt(Settings.getValue("UI", "width"));

        inX = Settings.getValue("Playground", "x");
        inY = Settings.getValue("Playground", "y");
        inZ = Settings.getValue("Playground", "z");



        AppController.agentAdded.connect(onAgentAdded);


    }

    function onAgentAdded(_id, _x, _y, _z)
    {
        var agent = UI.createObject("Agent.qml", rect);

        var x = map(_x, 0.0, inX, 0.0, w);
        var y = map(_y, 0.0, inY, h, 0.0);

        agent.setId(_id);
        agent.setPosition(x, y);
    }

    function map(_value, _inMin, _inMax, _outMin, _outMax)
    {
        return (_value-_inMin) * (_outMax-_outMin) / (_inMax-_inMin) + _outMin;
    }


}
