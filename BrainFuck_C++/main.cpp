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
    int turing[100];
    for(int i=0;i<100;i++){
        turing[i]=0;
    }
    int left_bracket=0;
    int id=0;
    int right_bracket=0;
    int input;
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
                cin>>input;
                turing[id]=input;
                break;
            case '[':
                if(turing[id]==0){
                    left_bracket=0;
                    while (index<brainfuck.length()) {
                        index++;
                        if(brainfuck[index]==']'&&left_bracket==0){
                            break;
                        }
                        if(brainfuck[index]==']'){
                            left_bracket--;
                        }
                        if(brainfuck[index]=='['){
                            left_bracket++;
                        }
                    }
                }
                break;
            case ']':
                if(turing[id]!=0){
                    right_bracket=0;
                    while (index>=0) {
                        index--;
                        if(brainfuck[index]=='['&&right_bracket==0){
                            break;
                        }
                        if(brainfuck[index]==']'){
                            right_bracket++;
                        }
                        if(brainfuck[index]=='['){
                            right_bracket--;
                        }
                    }
                }
                break;
        }
    }
    return 0;
}

