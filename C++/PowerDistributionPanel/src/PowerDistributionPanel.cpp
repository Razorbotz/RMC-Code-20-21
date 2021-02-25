
#include "PowerDistributionPanel.hpp"
#include <ncurses.h>

// This is hardcoded to a power panel at id 5   Sad!!!

PowerDistributionPanel::PowerDistributionPanel(){
	this->voltage=0;
}

float PowerDistributionPanel::getCurrent(int source){
	return currentA[source];
}

float PowerDistributionPanel::getCurrentB(int source){
	return currentB[source];
}

float PowerDistributionPanel::getCurrentC(int source){
	return currentC[source];
}

float PowerDistributionPanel::getVoltage(){
	return voltage;
}

void PowerDistributionPanel::parseFrame(struct can_frame frame){

        if(frame.can_id==0x88041485 || frame.can_id==0x88041545 || frame.can_id==0x88041605){
		parseVoltage(frame);
	}
	
	if(frame.can_id==0x88041405||
           frame.can_id==0x88041445||
           frame.can_id==0x88041485||
           frame.can_id==0x880414C5||
           frame.can_id==0x88041505||
           frame.can_id==0x88041545||
           frame.can_id==0x88041585||
           frame.can_id==0x880415C5||
           frame.can_id==0x88041605){
		parseCurrent(frame);
	}
        if(frame.can_id==0x88041645){
		//who knows
	}
}

void PowerDistributionPanel::parseVoltage(struct can_frame frame){
	if(frame.can_id==0x88041485 || frame.can_id==0x88041545 || frame.can_id==0x88041605){
		this->voltage=.05*frame.data[6]+4;
        }
}

void PowerDistributionPanel::parseCurrent(struct can_frame frame){
        float currentScalar = 0.125f;
        int i1=frame.data[0];
        i1=i1<<2;
        i1=i1|(frame.data[1]>>6 & 0x03);
        float current1=i1*currentScalar;

        int i2=frame.data[1] & 0x3f;
        i2=i2<<4;
        i2=i2|(frame.data[2]>>4 & 0x0f);
        float current2=i2*currentScalar;

        int i3=frame.data[2] & 0x0f;
        i3=i3<<6;
        i3=i3|(frame.data[3]>>2 & 0x3f);
        float current3=i3*currentScalar;

        int i4=frame.data[3] & 0x03;
        i4=i4<<8;
        i4=i4|(frame.data[4]);
        float current4=i4*currentScalar;

        int i5=frame.data[5];
        i5=i5<<2;
        i5=i5|(frame.data[6]>>6 & 0x03);
        float current5=i5*currentScalar;

        int i6=frame.data[6] & 0x3f;
        i6=i6<<4;
        i6=i6|(frame.data[7]>>4 & 0x7);
        float current6=i6*currentScalar;



	if(frame.can_id==0x88041405){
		this->currentA[0]=current1;
		this->currentA[1]=current2;
		this->currentA[2]=current3;
		this->currentA[3]=current4;
		this->currentA[4]=current5;
		this->currentA[5]=current6;
	}
        if(frame.can_id==0x88041445){
		this->currentA[6]=current1;
		this->currentA[7]=current2;
		this->currentA[8]=current3;
		this->currentA[9]=current4;
		this->currentA[10]=current5;
		this->currentA[11]=current6;
	}
        if(frame.can_id==0x88041485){
		this->currentA[12]=current1;
		this->currentA[13]=current2;
		this->currentA[14]=current3;
		this->currentA[15]=current4;
	}
        if(frame.can_id==0x880414C5){
		this->currentB[0]=current1;
		this->currentB[1]=current2;
		this->currentB[2]=current3;
		this->currentB[3]=current4;
		this->currentB[4]=current5;
		this->currentB[5]=current6;
	}
        if(frame.can_id==0x88041505){
		this->currentC[6]=current1;
		this->currentC[7]=current2;
		this->currentC[8]=current3;
		this->currentC[9]=current4;
		this->currentC[10]=current5;
		this->currentC[11]=current6;
	}
        if(frame.can_id==0x88041545){
		this->currentB[12]=current1;
		this->currentB[13]=current2;
		this->currentB[14]=current3;
		this->currentB[15]=current4;
	}
        if(frame.can_id==0x88041585){
		this->currentC[0]=current1;
		this->currentC[1]=current2;
		this->currentC[2]=current3;
		this->currentC[3]=current4;
		this->currentC[4]=current5;
		this->currentC[5]=current6;
	}
        if(frame.can_id==0x880415C5){
		this->currentC[6]=current1;
		this->currentC[7]=current2;
		this->currentC[8]=current3;
		this->currentC[9]=current4;
		this->currentC[10]=current5;
		this->currentC[11]=current6;
	}
        if(frame.can_id==0x88041605){
		this->currentC[12]=current1;
		this->currentC[13]=current2;
		this->currentC[14]=current3;
		this->currentC[15]=current4;
	}
}
