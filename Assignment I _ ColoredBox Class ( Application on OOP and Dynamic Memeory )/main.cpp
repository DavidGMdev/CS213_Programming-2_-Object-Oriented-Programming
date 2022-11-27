// ASSIGNMENT 1 :: OOP [programming 2]

/*
	Name 1 :: David George Monir 
	Id 1 :: 20201059
	Name 2 :: Bemwa malak 
	Id 2 :: 20200116
	Section :: S35 
	
*/

#include <iostream>
#include <windows.h>

using namespace std ;

// Assignmnet Required Class
class ColoredBox {
    private:
        // box itself 
        char ** box ; 
        // chrachter that form box itself
        char boxChar ;
        // dimentions of box [ Length , width ]
        int length   , width ;
        // Box color 
        int color; 
        
    public:
        // static memebers 

            // Biggest area among all objects [boxes]
            static int MaxArea ;

        // Static Member Functions

            // Geter for Maximum Area staticly saved
            static int getMaxArea () {
                return MaxArea ;
            }

        // Constructors 

                // Paramterized constructor [takes :: length , width , charachter( defult = # ) , color (defult = white) ]  
                ColoredBox ( int l , int w , int c = 15 , char x = '#') {

                        length = l , width = w , boxChar = x , color = c;

                        // Maximization Step 
                        if(l*w > MaxArea){
                            MaxArea = l*w;
                        }

                        // Box formulator :: Dynamic 2D array  
                        box = new char *[length] ;
                        for (int i = 0 ; i < length ; i++) {
                            box[i] = new char[width] ; 
                        }

                        // Generate Box  :: Filling up with charachter
                        for ( int i = 0 ; i < length ; i++ ) {
                            for ( int j = 0 ; j < width ; j++ ) {
                                    box[i][j] = boxChar ; 
                            }
                        }
                        // color 
                        setColor (color) ;

                }

        // Member Functions

            // Setters 
                // length 
                void setlength ( int l ) {
                        length = l ;
                }
                // width
                void setwidth ( int w ) {
                        width = w ; 
                }
                // character
                void setboxChar( int x) {
                        boxChar = x ;
                }
                // color
                void setColor(int c){
                    color = c;
                }
                

                void ChangeColor(int ForgC) {
                    WORD wColor;

                    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
                    CONSOLE_SCREEN_BUFFER_INFO csbi;

                    //We use csbi for the wAttributes word.
                    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
                        
                        //Mask out all but the background attribute, and add in the forgournd color
                        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
                        SetConsoleTextAttribute(hStdOut, wColor);
                    }
                    return ;
                }


            // Getters
                // length 
                int getlength () {
                    return length ; 
                }
                // width
                int getwidth () {
                    return width ;
                }
                // chrachter
                int getboxChar () {
                    return boxChar ; 
                }
                // color
                int getcolor () {
                    return color ; 
                }
                // Area
                int getArea () {
                    return length * width ; 
                }

            // Extra Functions
                // Printing Function
                 void display () {
                     //Applying color to the box characters
                     ChangeColor(color);
                     for ( int i = 0 ; i < length ; i++ ) {
                        for ( int j = 0 ; j < width ; j++ ) {
                            // normal display
                            cout << box[i][j] ;
                        }
                        cout <<  endl ;
                    }
                    //Returning to default console color (White)
                    ChangeColor(15);
                 }

                // Transposed Printing Function
                void displayTransposed () {
                    //Applying color to the box characters
                    ChangeColor(color);
                    // Reverse L , W loops and print 
                    for ( int i = 0 ; i < width ; i++ ) {
                        for ( int j = 0 ; j < length ; j++ ) {
                            // reflect l , w 
                            cout << box[j][i]  ;
                        }
                        cout <<  endl ;
                    }
                    //Returning to default console color (White)
                    ChangeColor(15);
                }

                // Wider [extra spacing] Function
                void displayWider () {
                    //Applying color to the box characters
                    ChangeColor(color);
                    // print Space , and extra endline
                    for ( int i = 0 ; i < length ; i++ ) {
                        for ( int j = 0 ; j < width ; j++ ) {
                            // extra space lining
                            cout << box[i][j] << ' ' ;
                        }
                        cout << endl ;
                    }
                    //Returning to default console color (White)
                    ChangeColor(15);
                }

                // displayChess Function
                void displayChess ( int color2 ) {
                    // Alternate between color 1 and color 2 
                    int f = 1; 
                    for ( int i = 0 ; i < length ; i++ ) {
                        for ( int j = 0 ; j < width ; j++ ) {
                            if (f) {
                                // color 1 
                                //Applying color to the box characters
                                ChangeColor(color);
                                cout << box[i][j] ;
                            }
                            else {
                                //Applying color2 to the box characters
                                ChangeColor(color2);
                                cout << box[i][j] ;
                            }
                            f = !f;
                        }
                        cout << endl ;
                    }
                    //Returning to default console color (White)
                    ChangeColor(15);
                }

        // Destructor
        ~ColoredBox() {
            // realseing dynaminc memorey
            for (int i = 0 ; i < length ; i++) {
                 delete [] box[i] ; 
            }
            delete [] box ; 
            //Making new line after the object has been destroyed for better formatting
            cout << endl;
        }
};

// intialize the Static memeber max Area  
int ColoredBox :: MaxArea = 0 ; 

int main() {

    // Constructing 1st Object ::: 
    int len , wid , col , col2 ;
    char boxChar;
    cout << "Enter length and width of the box separated by a space: " ;
    cin >> len >> wid ;
    ColoredBox* cb1;
    cb1 = new ColoredBox(len,wid);

    // Applying Functions ::

        // display 
        cb1 -> display();

        // Change color 
        cout << "Set the box to another color: " ;
        cin >> col ;
        cb1 -> setColor(col);

        // Transposed dispaly 
        cout << "Displaying Transposed: " << endl;
        cb1 -> displayTransposed();

        // Widley dispaly 
        cout << "Displaying Wider: " << endl;
        cb1 -> displayWider();

        // Chess display
        cout << "Displaying Chess, enter the other color: " << endl;
        cin >> col2;
        cb1 -> displayChess(col2);

        // Area & Max area till now
        cout << endl << "Area=" << cb1 -> getArea() ;
        cout << endl << "Max Area=" << cb1 -> getMaxArea();

    // relase memeory 
    delete cb1;

    // Constructing 2nd Object ::: 
    cout << "Enter length,width,color,character of the box separated by spaces: "  ;
    cin >> len >> wid >> col >> boxChar ;
    ColoredBox* cb2;
    cb2 = new ColoredBox( len , wid , col , boxChar );
    
    // Applying Functions ::

        // Normal Display
        cb2 -> display() ;

        // Transposed dispaly 
        cout << "Displaying Transposed: " << endl ;
        cb2 -> displayTransposed();

        // Widley dispaly 
        cout << "Displaying Wider: " << endl ;
        cb2 -> displayWider();

        // Chess display
        cout << "Displaying Chess, enter the other color: " << endl ;
        cin >> col2;
        cb2 -> displayChess(col2);

        // Normal Display
        cout << "Displaying original again:" << endl ;
        cb2 -> display();

        // Area & Max area till now
        cout << endl << "Area= " << cb2 -> getArea() ;
        cout << endl << "Max Area= " << cb2 -> getMaxArea() ;

    // relase memeory 
    delete cb2;

}
