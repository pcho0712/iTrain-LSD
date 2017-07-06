//
//  TextContent.hpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/07/07.
//
//

#ifndef TextContent_hpp
#define TextContent_hpp

#include <stdio.h>
#include <ofMain.h>




class TextContent{
public:
    string text;
    unsigned char length;
    //    unsigned char* text;
    //    unsigned char length;
    
    TextContent();
    TextContent(string);
    ~TextContent();
    
    //    void setLength(unsigned char);
    void setText(string);
    string getText();
    unsigned char get(int);
	void set4dig(long);
    
};


#endif /* TextContent_hpp */
