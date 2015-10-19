import QtQuick 2.0
import QtQuick.Window 2.1
import QtQuick.Dialogs 1.2
Item {
    property int previousTileIndex: 0;
    signal stopGame
    Column{
        ChessBoard{
            mouseAreaEnable: true;
            showPieceImages: true;
            chessGameModel: chessModel
        }
        Rectangle{
            id: matchInfo
            color: "#FFFFFF"
            width: parent.parent.width
            height: parent.parent.height/9
            Row{
                //spacing:
                Rectangle {
                    height: parent.parent.height
                    width: parent.parent.width/8
                    Text{
                        anchors.centerIn: parent
                        text: "White"
                    }
                }
                Text{
                    height: parent.parent.height
                    width: parent.parent.width/8
                    verticalAlignment :Text.AlignVCenter
                    //anchors.centerIn: parent
                    text: chessModel.totalWhiteTime
                }
                Rectangle {
                    height: parent.parent.height
                    width: parent.parent.width/8
                }
                Rectangle {
                    id: stopButton
                    color: "#20B2AA"
                    height: parent.parent.height
                    width: parent.parent.width/8
                    Text{
                        id: stopButtonLabel
                        anchors.centerIn: parent
                        text: "Stop"
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            chessModel.StopGame()
                            stopGame();
                        }
                    }
                }

                Rectangle {
                    id: saveButton
                    color: "#20B2AA"
                    height: parent.parent.height
                    width: parent.parent.width/8
                    Text{
                        id: saveButtonLabel
                        anchors.centerIn: parent
                        text: "Save"
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            chessModel.StopGame()
                            fileDialog.visible = true;
                        }
                    }
                }
                Rectangle {
                    height: parent.parent.height
                    width: parent.parent.width/8
                }
                Text{
                    height: parent.parent.height
                    width: parent.parent.width/8
                    verticalAlignment :Text.AlignVCenter
                    horizontalAlignment: Text.AlignRight
                    text: chessModel.totalBlackTime
                }
                Rectangle {
                    height: parent.parent.height
                    width: parent.parent.width/8
                    Text{
                        verticalAlignment :Text.AlignVCenter
                        anchors.centerIn: parent
                        text: "Black"
                    }
                }
            }
        }
    }
    onVisibleChanged: {
        if(visible){
            chessModel.Initialise()
            chessModel.RefreshView();
            chessModel.StartGame();
        }
    }
    FileDialog{
        id: fileDialog
        title: "Please choose a file"
        folder: appPath
        selectMultiple: false
        selectExisting: false
        nameFilters: [ "Chess Files (*.chs)", "All files (*)" ]
        onAccepted: {
            if(chessModel.SaveGame(fileDialog.fileUrl) === -1){
                messageDialog.visible = true;
            }
            chessModel.StartGame()//lets not stop the game
        }
        onRejected: {
            chessModel.StartGame();
        }
        Component.onCompleted: visible = false
    }
        MessageDialog {
            id: messageDialog
            title: "Warning"
            text: chessModel.warning
            Component.onCompleted: visible = false
        }
}

