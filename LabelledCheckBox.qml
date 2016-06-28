import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle{
    signal checkBoxCheckedChanged(bool _value)

    id: rect

    width: parent.width
    color: "transparent"

    function setLabel(_text)
    {
        label.text = _text;
    }

    Text {
        id: label
        color: "white"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        width: parent.width / 3;
    }

    CheckBox{
        id: checkBox
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: label.right
        width: parent.width / 3 * 2;

        onCheckedChanged: checkBoxCheckedChanged(checked)
    }

}
