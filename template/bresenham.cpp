#include<cmath>

// 0<=dy<=dx; for the line in first octet round
void line(int x1, int y1, int x2, int y2){
    int dx, dy;
    int x,y,e;
    x = x1, y = y1;
    dx = x2 - x1; dy = y2 - y1;
    e = 2 * dy - dx;
    for(int i=0; i<dx; i++){
        draw(x, y);
        while(e > 0){
            ++y;
            e += 2 * dx;
        }
        ++x;
        e += 2 * dy;
    }
}

int inline sign(int v){
    if(v > 0) return 1;
    if(v == 0) return 0;
    return -1;
}
// for general line
void line(int x1, int y1, int x2, int y2){
    int x, y, dx, dy, sx, sy;
    bool interchange = false;
    x=x1, y=y1;
    dx = abs(x2 - x1); dy = abs(x2 - x1);
    sx = sign(dx); sy=sign(dy);
    if(dy > dx){
        swap(dx, dy);
        interchange = true;
    }
    int e = 2 * dy - dx;
    for(int i=0; i<dx; i++){
        draw(x, y);
        while(e > 0){
            if(interchange){
                x += sx;
            } else {
                y += sy;
            }
            e -= 2 * dx;
        }
        if(interchange){
            y += sy;
        } else {
            x += sx;
        }
        e += 2*dy;
    }

}

