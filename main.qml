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

    LabelledSlider{
        width: parent.width
        id: timeSlider
        height: 25
        Component.onCompleted: {
            var simTime = parseInt(Settings.getValue("Simulation", "time"));
            if(simTime<=0)
                timeSlider.visible = false;

            timeSlider.setLabelKey("Time[s]: $value");
            timeSlider.setValueRange(0, simTime);
            timeSlider.setSliderValue(0);
        }
        onSliderValueChanged: {
            var currentValue = parseInt(_value);
            AppController.setSimTime(currentValue*1000);
        }
    }
}
