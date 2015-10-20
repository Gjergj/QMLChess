import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
ApplicationWindow {
    title: qsTr("Chess")
    width: 560
    height: 560
    visible: true

    id: mainWindow
    flags: Qt.Dialog
    modality: Qt.ApplicationModal
    property variant win;
    StartScreen{
        id: startScreen
        visible: true
        width: parent.width
        height: parent.height
        onPlayGame:{
            startScreen.state = "GamePlay";
        }
        onReplayGame:{
            startScreen.state = "GameRePlay";
        }
        state: "StartScreen"

            states: [
                State {
                    name: "StartScreen"
                    PropertyChanges { target: startScreen; visible: true}
                    PropertyChanges { target: gamePlay; visible: false}
                    PropertyChanges { target: gameRePlay; visible: false}
                },
                State {
                    name: "GamePlay"
                    PropertyChanges { target: startScreen; visible: false}
                    PropertyChanges { target: gamePlay; visible: true}
                    PropertyChanges { target: gameRePlay; visible: false}
                },
                State {
                    name: "GameRePlay"
                    PropertyChanges { target: startScreen; visible: false}
                    PropertyChanges { target: gamePlay; visible: false}
                    PropertyChanges { target: gameRePlay; visible: true}
                }
            ]
    }

    GamePlay{
        id: gamePlay
        visible: false
        width: parent.width
        height: parent.height
        onStopGame:{
            startScreen.state = "StartScreen";
        }
    }
    GameReplay{
        id: gameRePlay
        visible: false
        width: parent.width
        height: parent.height
        onStartNewGame: {
            startScreen.state = "GamePlay";
        }
    }
}
