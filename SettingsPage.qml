import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle {
    visible: false
    color: "#3B303D"
    //anchors.fill: parent

    Rectangle{
        width: parent.width
        height: 2
        color: "black"
    }


    width: parent.width
    height: 100

    Column{
        width: parent.width

        LabelledSlider{
            width: parent.width/2
            id: gammaSlider
            height: 25
            Component.onCompleted: {
                var value = Settings.getValue("ChannelModel", "gamma");
                gammaSlider.setLabelKey("Gamma: $value");
                gammaSlider.setValueRange(1, 7);
                gammaSlider.setSliderValue(value);
            }
            onSliderValueChanged: {
                AppController.setChannelModelParameter("gamma", _value)
            }
        }


        LabelledTextField{
            width: parent.width/2
            id: psField
            height: 25
            Component.onCompleted: {
                var value = Settings.getValue("ChannelModel", "Ps")
                //psField.setLayoutRatio(1, 2);
                psField.setValue(value);
                psField.setLabel("Transmission Power [mW]")
            }
            onTextFieldChanged: {
                AppController.setChannelModelParameter("Ps", parseFloat(_value))
            }
        }

        LabelledTextField{
            width: parent.width/2
            id: fField
            height: 25
            Component.onCompleted: {
                var value = Settings.getValue("ChannelModel", "f")
               // psField.setLayoutRatio(1, 2);
                fField.setValue(value);
                fField.setLabel("Frequency [GHz]")
            }
            onTextFieldChanged: {
                AppController.setChannelModelParameter("f", parseFloat(_value))
            }
        }

        LabelledCheckBox{
            width: parent.width/2
            id: coverageField
            height: 25
            Component.onCompleted: {
                coverageField.setLabel("Show Coverage")
            }
            onCheckBoxCheckedChanged: {
                AppController.setChannelModelParameter("coverage", _value)
            }
        }

    }






}
