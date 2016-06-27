import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
    visible: false
    color: "#6e6e6e"
    //anchors.fill: parent

    Rectangle{
        width: parent.width
        height: 2
        color: "black"
    }


    width: parent.width
    height: 100

    Component.onCompleted: {
        alpha.value = Settings.getValue("ChannelModel", "gamma");
    }

    Text {
        id: name
        text: "Gamma: "
        color: "white"
        width: parent.width/5
    }
    Slider{
        id: alpha
        minimumValue: 1
        maximumValue: 7
        width: parent.width/5*4
        anchors.left: name.right

        onValueChanged: {
            AppController.handleGammaChange(value);
            name.text = "Gamma: " + value
        }
    }


}
