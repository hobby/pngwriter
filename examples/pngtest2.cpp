#include <pngwriter.h>
#include <iostream>

using namespace std;

int main()
{
   int i;
   int y;

   pngwriter png(800,260,0xe600,"800x260.png");
  
   for(i = 1; i < 800;i++)
   {
     	y = 150+100*sin((double)i*9/800.0);     	
        png.plot(i,y, 52992, 59648, 64256);
   }     
   png.close();

   pngwriter png2;
   png2.readfromfile("test1.png");
   cout << png2.read(10,10, 1) << "," << png2.read(10,10,2) << "," << png2.read(10,10,3) << endl;
   cout << png2.read(10,10) << endl;
   return 0;
}
