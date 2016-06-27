import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true


    Component.onCompleted: {
        height = Settings.getValue("UI", "height");
        width = Settings.getValue("UI", "width");
        maximumHeight = height;
        maximumWidth = width;
        minimumHeight = height;
        minimumWidth = width;

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

    MissionArea{
        id: missionArea

        focus: true
        Keys.onPressed: {
            if(event.key==Qt.Key_H)
            {
                if(settingsPage.visible==true)
                    settingsPage.visible = false;
                else
                    settingsPage.visible = true;
            }
        }


    }

    SettingsPage
    {
        id: settingsPage
        anchors.bottom: parent.bottom
    }

    Text {
        id: simTimeLabel
        text: "Time[s]: "
        color: "white"
        width: parent.width/8
    }

    Slider {
        width: parent.width/8*6
        id: slider
        anchors.left: simTimeLabel.right

        onValueChanged: {
            var currentValue = parseInt(value);
            simTimeLabel.text = "Time[s]: " + currentValue;
            AppController.setSimTime(currentValue*1000);

            missionArea.test(currentValue);
        }
    }
}
