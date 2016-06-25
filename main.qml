import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true

    Component.onCompleted: {
        height = Settings.getValue("UI", "height");
        width = Settings.getValue("UI", "width");

        var simTime = parseInt(Settings.getValue("Simulation", "time"));

        slider.minimumValue = 0;
        slider.maximumValue = simTime;
    }

    function createAgent(_id, _x, _y, _z, _alpha)
    {
        var agent = UI.createObject("Agent.qml");
        agent.setPosition(_x, _y);

        _map.addMapItem(agent)

        return agent;
    }

    MissionArea{}

    Slider {
        width: parent.width
        id: slider

        onValueChanged: {
            var currentValue = parseInt(value);
            AppController.setSimTime(currentValue*1000);
        }
    }
}
