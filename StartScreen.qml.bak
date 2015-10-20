import QtQuick 2.0
import QtQuick.Dialogs 1.2
//import QtQuick.Layouts 1.1
Item {
    signal playGame;
    signal replayGame;
    Column{
        height: parent.height
        width: parent.width
        ChessBoard{
            chessGameModel: 64
        }
        Row{
            height: parent.height
            width: parent.width
            Rectangle {
                height: parent.height/9
                width: parent.width/8
            }
            Rectangle {
                height: parent.height/9
                width: parent.width/8
            }
            Rectangle {
                id: simplebutton
                color: "#20B2AA"
                height: parent.height/9
                width: parent.width/8

                Text{
                    id: buttonLabel
                    anchors.centerIn: parent
                    text: "Start"
                }
                MouseArea{
                    id: buttonMouseArea
                    anchors.fill: parent
                    onClicked: {
                        playGame();
                    }
                }
            }
            Rectangle {
                height: parent.height/9
                width: parent.width/8
            }
            Rectangle {
                id: simplebutton1
                color: "#20B2AA"
                height: parent.height/9
                width: parent.width/8

                Text{
                    id: buttonLabel1
                    anchors.centerIn: parent
                    text: "Load"
                }
                MouseArea{
                    id: buttonMouseArea1
                    anchors.fill: parent
                    onClicked: fileDialog.visible = true
                }
            }
        }
        FileDialog {
            id: fileDialog
            title: "Please choose a game file"
            folder: appPath
            visible: false;
            nameFilters: [ "Chess Files (*.chs)", "All files (*)" ]
            selectMultiple: false
            onAccepted: {
                chessModel.Initialise()
                if(chessModel.LoadGame(fileDialog.fileUrl) === -1)
                    messageDialog.visible = true;
                replayGame();
            }
            onRejected: {
            }
        }
    }
}

