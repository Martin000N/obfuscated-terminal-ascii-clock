// Copyright (c) 2024 Martin Novak

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include<stdio.h>
#include<time.h>
#include<math.h>

int main(){
    while(1){
        char b[50][100]={0};
        int t=((time(0)+7200)%86400);
        int p[3][3]={{7.0f*sin(-t*0.000145f),7.0f*cos(t*0.000145f),1},
                     {10.0f*sin(-t*0.00175f),10.0f*cos(t*0.00175f),2},
                     {15.0f*sin(-t*0.10472f),15.0f*cos(t*0.10472f),3}}; 
        for(int i=0;i<3;++i){
            int r=(p[i][0])+50,t=50,z=p[i][1]+25,q=25,d1=abs(r-t),sx=t<r?1:-1,d2=-abs(z-q),sy=q<z?1:-1,e=d1+d2,e2;
            for(;!(t==r&&q==z);){
                if (!(q>=100||t>=100||q<0||t<0))b[q][t]=p[i][2];e2=2*e;(e2>=d2)?(e+=d2,t+=sx):(e+=d1,q+=sy);
            }
            if (!(q>=100||t>=100||q<0||t<0))b[q][t]=p[i][2];
        }
        for(int y=50-1;y>=0;y--){
            for(int x=100-1;x>=0;x--){
                b[y][x]==1?printf("\x1b[31m%c",64):(b[y][x]==2?printf("\x1b[32m%c",64):(b[y][x]==3?printf("\x1b[34m%c",64):printf("\x1b[36m%c",(((x-50)*(x-50))/2+(y-25)*(y-25)<400?(((x-50)*(x-50))/2+(y-25)*(y-25)<200?35:51):32))));
                printf("\x1b[0m");
            }
            puts("");
        }   
        printf ("\x1b[d");
    }
}
