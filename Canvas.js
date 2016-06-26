.pragma library

function grad2rad(_grad)
{
    return _grad*Math.PI/180;
}

function clear(_ctx, _x, _y)
{
    _ctx.clearRect(0, 0, _x, _y);
}

function rotate(_ctx, _x, _y, _angle)
{
    _ctx.translate(_x,_y);
    _ctx.rotate(grad2rad(_angle));
    _ctx.translate(-_x,-_y);
}

function drawLine(_ctx, _x0, _y0, _x1, _y1, _color)
{
    _ctx.strokeStyle = _color;
    _ctx.beginPath();
    _ctx.moveTo(_x0, _y0);
    _ctx.lineTo(_x1, _y1);
    _ctx.stroke();
}

function drawArc(_ctx, _x, _y, _r, _start, _end, _clockWise, _color)
{
    _ctx.fillStyle = _color;
    _ctx.beginPath()
    _ctx.arc(_x, _y, _r, _start, _end, _clockWise);
    _ctx.closePath();
    _ctx.fill();
}
