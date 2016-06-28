import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle{
    signal textFieldChanged(string _value)
    id: rect

    width: parent.width
    color: "transparent"


    function setValue(_value)
    {
        textField.text = _value;
    }

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

    TextField{
        id: textField
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: label.right
        width: parent.width / 3 * 2;

        onTextChanged: textFieldChanged(text);
    }

}
