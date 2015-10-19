import QtQuick 2.0
Grid {
    id: gX
    property alias chessGameModel: repX.model
    property bool showPieceImages: false;
    property bool mouseAreaEnable: false
    rows: 8; columns: 8; spacing: 0;
    Repeater {
        id: repX
        delegate: Item {
            id: delegateContainer
            width: parent.parent.parent.width/8;
            height: parent.parent.parent.height/9
            property alias tileColor: tile.color
            Rectangle {
                id: tile
                color:  ((Math.floor(index / 8) % 2) === 0)
                        ?
                            (index % 2  === 1 ? "#D18B47" : "#FFCE9E")
                          :
                            (index % 2  === 0 ? "#D18B47" : "#FFCE9E")
                anchors.fill: parent
                Image {
                    id: fig
                    anchors.fill: parent
                    fillMode: Image.PreserveAspectFit
                    anchors.centerIn: parent
                    source: showPieceImages ? model.CellImageSource : ""
                }
            }
            MouseArea {
                enabled: mouseAreaEnable
                anchors.fill: parent
                onClicked: {
                    var changeColor = chessModel.PieceClicked(index)
                    if(changeColor === 1){
                        tile.color = "#FF0000"//highlight
                        previousTileIndex = index;
                    }
                    else if(changeColor === 2){
                        return; //do not change color
                    }
                    else{
                        repX.itemAt(previousTileIndex).tileColor =
                                ((Math.floor(previousTileIndex / 8) % 2) === 0)
                                ?
                                    (previousTileIndex % 2  === 1 ? "#D18B47" : "#FFCE9E")
                                  :
                                    (previousTileIndex % 2  === 0 ? "#D18B47" : "#FFCE9E");
                        tile.color = ((Math.floor(index / 8) % 2) === 0)
                                ?
                                    (index % 2  === 1 ? "#D18B47" : "#FFCE9E")
                                  :
                                    (index % 2  === 0 ? "#D18B47" : "#FFCE9E");
                    }
                }
            }
        }
    }
}
