//
//  main.cpp
//  BrainFuck_C++
//
//  Created by 郝宇泽 on 2018/3/3.
//  Copyright © 2018年 SmallE. All rights reserved.
//

#include <iostream>
#include "string"
using namespace std;

int main(int argc, const char * argv[]) {
    string brainfuck = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
    string brainfuck01 = ">>>++[<++++++++[<[<++>-]>>[>>]+>>+[-[->>+<<<[<[<<]<+>]>[>[>>]]]<[>>[-]]>[>[-<<]>[<+<]]+<<]<[>+<-]>>-]<.[-]>>]";
    brainfuck=brainfuck01;
    int turing[100];
    for(int i=0;i<100;i++){
        turing[i]=0;
    }
    int go=0;
    int id=0;
    int re=0;
    int n;
    for(int index=0;index<brainfuck.length();index++){
        switch (brainfuck[index]) {
            case '>':
                id++;
                break;
            case '<':
                id--;
                break;
            case '+':
                turing[id]++;
                break;
            case '-':
                turing[id]--;
                break;
            case '.':
                cout<<(char)turing[id];
                break;
            case ',':
                cin>>n;
                turing[id]=n;
                break;
            case '[':
                if(turing[id]==0){
                    go=0;
                    while (index<brainfuck.length()) {
                        index++;
                        if(brainfuck[index]==']'&&go==0){
                            break;
                        }
                        if(brainfuck[index]==']'){
                            go--;
                        }
                        if(brainfuck[index]=='['){
                            go++;
                        }
                    }
                }
                break;
            case ']':
                if(turing[id]!=0){
                    re=0;
                    while (index>=0) {
                        index--;
                        if(brainfuck[index]=='['&&re==0){
                            break;
                        }
                        if(brainfuck[index]==']'){
                            re++;
                        }
                        if(brainfuck[index]=='['){
                            re--;
                        }
                    }
                }
                break;
        }
    }
    return 0;
}

