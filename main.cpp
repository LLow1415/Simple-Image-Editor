#include <iostream>
#include "CImg.h"
#include <Magick++.h>
using namespace cimg_library;
using namespace Magick;
using namespace std;

int main(int argc,char **argv) {
    cout << "Input File Location Below:" << endl;
    string location;
    string newLocation = location;
    MagickPlusPlusGenesis genesis(*argv);
    cin >> location;

    Image image;
    try {
        image.read(location);
        int choice = 0;
        while (choice !=4) {
            cout << "[1]Text, [2]Flip, [3]Convert [4]Quit" << endl;
            cin >> choice;
            string topText;
            string bottomText;
            int extension;
            string format;
            switch (choice) {
                case 1:
                    image.font("font.ttf");
                    image.fontPointsize(150);
                    image.fillColor("white");
                    image.strokeColor("black");
                    image.strokeWidth(1);
                    cout << "Top Text" << endl;
                    cin >> topText;
                    image.annotate(topText, Geometry(+"+50+50"), NorthGravity);
                    cout << "Bottom Text" << endl;
                    cin >> bottomText;
                    image.annotate(bottomText, Geometry(+"+50+50"), SouthGravity);
                    break;
                case 2:
                    image.flip();
                    break;
                case 3:
                    extension = location.find_last_of('.');
                    cout << "png, jpg, webp" << endl;
                    cin >> format;
                    newLocation = location.substr(0, extension+1)+format;
                    choice = 4;
                    break;
            }
        }
        cout << "[1]Save, [2]Discard" << endl;
        cin >> choice;

        if (choice == 1) {
            image.write(newLocation);
        }

    }
    catch( Exception &error_ )
    {
        cout << "Caught exception: " << error_.what() << endl;
        return 1;
    }

    return 0;
}

