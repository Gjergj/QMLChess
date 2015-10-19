import QtQuick 2.0
import QtQuick.Window 2.1
import QtQuick.Dialogs 1.2
Item {
    property int previousTileIndex: 0;
    signal startNewGame
    Column{
        height: parent.height
        width: parent.width
        ChessBoard{
            showPieceImages: true;
            chessGameModel: chessModel
        }
        Rectangle{
            id: matchInfo
            color: "#FFFFFF"
            width: parent.parent.width
            height: parent.parent.height/9
            Row{
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
                    text: chessModel.totalWhiteTime
                }
                Rectangle {
                    id: startButton
                    color: "#20B2AA"
                    height: parent.parent.height
                    width: parent.parent.width/8
                    Text{
                        id: startButtonLabel
                        anchors.centerIn: parent
                        text: "Start"
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            startNewGame();
                        }
                    }
                }
                Rectangle {
                    id: previousButton
                    color: "#20B2AA"
                    height: parent.parent.height
                    width: parent.parent.width/8
                    Text{
                        id: previousButtonLabel
                        anchors.centerIn: parent
                        text: "Previous"
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            if(chessModel.PlayPreviousMove() === -1)
                                messageDialog.visible = true;
                        }
                    }
                }
                Rectangle {
                    id: nextButton
                    color: "#20B2AA"
                    height: parent.parent.height
                    width: parent.parent.width/8
                    Text{
                        id: nextButtonLabel
                        anchors.centerIn: parent
                        text: "Next"
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            if(chessModel.PlayNextMove() === -1)
                                messageDialog.visible = true;

                        }
                    }
                }

                Rectangle {
                    id: loadButton
                    color: "#20B2AA"
                    height: parent.parent.height
                    width: parent.parent.width/8
                    Text{
                        id: loadButtonLabel
                        anchors.centerIn: parent
                        text: "Load"
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            fileDialog.visible = true;
                        }
                    }
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
            chessModel.RefreshView();
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
            chessModel.Initialise();
            if(chessModel.LoadGame(fileDialog.fileUrl) === -1)
                messageDialog.visible = true;
            chessModel.RefreshView();
        }
        onRejected: {
        }
    }
    MessageDialog {
        id: messageDialog
        title: "Warning"
        text: chessModel.warning
        Component.onCompleted: visible = false
    }
}

