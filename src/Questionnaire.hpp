//
//  Questionnaire.hpp
//  iTrain-LSD
//
//  Created by 吉田貴寿 on 2017/07/07.
//
//

#ifndef Questionnaire_hpp
#define Questionnaire_hpp

#include <stdio.h>
#include <ofMain.h>
#include "TextContent.hpp"



class QContent{
public:
    TextContent content;
    int totalYes;
    int totalNo;
    
    QContent();
    ~QContent();
    
};


enum QState {
    STATE_QUESTION, STATE_ANSWER, STATE_RESULT
};


class Questioner{
    
    QContent qContent;
    QState currentState;
    
    Questioner();
    ~Questioner();

    
    void moderate();//司会進行
    
    
    void displayQuestion();
    void displayAnswer();
    void displayResult();
    
};





#endif /* Questionnaire_hpp */
