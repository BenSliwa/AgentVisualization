import QtQuick 2.0

Rectangle {
    property string m_id: ""
    signal positionUpdateResponse(double _x, double _y, double _z)

    width: 128; height: width

    //color: "blue"
    color: "transparent"

    radius: width*0.5
    Image {
        anchors.fill: parent
        id: icon
        source: "Images/uav_64.png"
        fillMode: Image.PreserveAspectFit


    }

    MouseArea{
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked:
        {
            if(mouse.button & Qt.LeftButton) {
                AppController.handleAgentLeftClick(m_id);
            }
            else if(mouse.button & Qt.RightButton) {
                AppController.handleAgentRightClick(m_id);
            }

        }

    }

    Text {
        anchors.verticalCenter: icon.verticalCenter
        anchors.horizontalCenter: icon.horizontalCenter

        id: text
        font.pointSize: 15
        color: "white"
    }

    Component.onCompleted: {
        parent.agentPositionUpdated.connect(onAgentPositionUpdated);
        parent.requestPositionUpdates.connect(onPositionUpdateRequest);
    }

    function toggleVisibility()
    {
        if(visible)
            visible = false;
        else
            visible = true;
    }

    function setId(_id)
    {
        m_id = _id;
        text.text = _id;
    }

    function onAgentPositionUpdated(_id, _x, _y, _z)
    {
        if(_id==m_id)
            setPosition(_x, _y);
    }

    function onPositionUpdateRequest()
    {
        parent.onPositionUpdateResponse(x+width/2, y+height/2, 0);
    }

    function setPosition(_x, _y)
    {
        x = _x - icon.width/2;
        y = _y - icon.height/2;
    }
}
