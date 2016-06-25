.pragma library


function createObject(_component, _parent)
{
    var component = Qt.createComponent(_component);
    var object = component.createObject(_parent);

    return object;
}

