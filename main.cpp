#define SDL_MAIN_HANDLED

#include "Memake/Memake.h"


// RAII - Testing
#include "Memake/Timer.h"

Memake mmk(1000, 500, "memake");

using namespace std;

class Ball {
    public:
        Ball(){}
        int x, y, r;

        Ball(int _x, int _y, int _r) {
            x = _x;
            y = _y;
            r = _r;
        }



        void draw() {
            mmk.drawCircle(x, y, r, Colmake.beige);
        }
};

class Square {
    public:
        Square(){}
        int x, y, width, height;

        Square(int _x, int _y, int _width, int _height) {
            x = _x;
            y = _y;
            width = _width;
	    height = _height;
        }



        void draw() {
            mmk.drawRect(x, y, width, height, Colmake.red);
        }
};


class Delta {
    public:
        Delta(){}
        int x1, y1, x2, y2, x3, y3;

        Delta(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3) {
            x1 = _x1;
            y1 = _y1;
            x2 = _x2;
	    y2 = _y2;
            x3 = _x3;
	    y3 = _y3;	    
        }



        void draw() {
            mmk.drawTriangle(x1, y1, x2, y1, x3, y3, Colmake.blue);
        }
};



int main()
{
    int numOfBall = 10;
    int numOfSquare = 10; 
    int numOfDelta = 10; 
    Ball b[numOfBall];
    Square s[numOfSquare];
    Delta d[numOfDelta];

    // generate ball to total X numOfBall
    for (int i = 0; i < numOfBall; i++) {
        b[i] = Ball(mmk.getScreenW()-(i+1)*100+50, mmk.getScreenH()/2, 10);
	s[i] = Square(mmk.getScreenW()-(i+1)*100+50, mmk.getScreenH()-100, 10,10);
	d[i] = Delta(mmk.getScreenW()-(i+1)*100+40, mmk.getScreenH()-400-10, mmk.getScreenW()-(i+1)*100+60, mmk.getScreenH()-400+10,mmk.getScreenW()-(i+1)*100+50, mmk.getScreenH()-400);
	
    }
    



    // animate ball
    mmk.update([&](){
        {
            Timer timer;

            for (int i = 0; i < numOfBall; i++) {
       
                b[i].draw();
		s[i].draw();
		d[i].draw();
            }
        }

        cout << "one frame has ended" << endl << endl;
    });
    


    return 0;
}
