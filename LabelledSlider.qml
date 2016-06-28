import QtQuick 2.0
import QtQuick.Controls 1.4


Rectangle{
    signal sliderValueChanged(double _value)

    property string m_key: ""

    width: parent.width
    color: "transparent"

    function setSliderValue(_value)
    {
        slider.value = _value;
    }

    function setValueRange(_min, _max)
    {
        slider.minimumValue = _min;
        slider.maximumValue = _max;
    }

    function setLabelKey(_key)
    {
        m_key = _key;
    }

    function setLabelText(_value)
    {
        var text = m_key;
        text = text.replace("$value", _value);

        label.text = text;
    }

    Text {
        id: label
        color: "white"
        width: parent.width/3

        anchors.verticalCenter: parent.verticalCenter
    }
    Slider{
        id: slider
        width: parent.width/3*2

        anchors.left: label.right
        anchors.verticalCenter: parent.verticalCenter


        onValueChanged: {
            setLabelText(value.toFixed(3));
            sliderValueChanged(value);
        }
    }

}
