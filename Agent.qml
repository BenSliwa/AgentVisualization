import QtQuick 2.0



Rectangle {
    property string m_id: ""

    //x: parent.width/+2-width/2; y: parent.height/2-height/2
    width: 30; height: width
    color: "blue"

    radius: width*0.5

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
        anchors.centerIn: parent
        id: text
        font.pointSize: 15
        color: "white"
    }

    Component.onCompleted: {
        //AppController.agentPositionUpdated.connect(onAgentPositionUpdated);
        parent.agentPositionUpdated.connect(onAgentPositionUpdated);
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

    function setPosition(_x, _y)
    {
        x = _x - width/2;
        y = _y - height/2;

        // TODO: hier fehlt das mapping

    }
}
