//
//  TextContent.cpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/07/07.
//
//

#include "TextContent.hpp"



TextContent::TextContent(){
    
}

TextContent::TextContent(string str){
    setText(str);
}
TextContent::~TextContent(){
    
}

//void setLength(unsigned char _len){
//    length = _len;
//}

void TextContent::setText(string str){
    text = str;
}

string TextContent::getText(){
    return text;
}

unsigned char TextContent::get(int n){
    return text[n];
}





