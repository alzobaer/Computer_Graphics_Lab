#include <graphics.h>
#include <iostream>
#include <math.h>

struct PT{
	int x;
	int y;
	char code[4];
};

void drawWindow(){
	line(150, 100, 450, 100);
	line(450, 100, 450, 350);
	line(450, 350, 150, 350);
	line(150, 350, 150, 100);
}

void drawLine(PT p1, PT p2){
	line(p1.x, p1.y, p2.x, p2.y);
}

PT setCode(PT p){
	PT ptemp;

	if(p.y < 100)	// Top
		ptemp.code[0] = '1';
	else
		ptemp.code[0] = '0';

	if(p.y > 350)	// Bottom
		ptemp.code[1] = '1';
	else
		ptemp.code[1] = '0';

	if(p.x > 450)	// Right
		ptemp.code[2] = '1';
	else
		ptemp.code[2] = '0';

	if(p.x < 150)	// Left
		ptemp.code[3] = '1';
	else
		ptemp.code[3] = '0';

	ptemp.x = p.x;
	ptemp.y = p.y;

	return(ptemp);
}

int visibility(PT p1, PT p2){
	int flag = 0;

	// when the line is inside of the window
	for(int i = 0; i < 4; i++){
		if((p1.code[i] != '0') || (p2.code[i] != '0'))
			flag = 1;
	}
	//printf("%d", flag);
	if(flag == 0)
		return(0);

	// when the line is outside of the window
	for(int i = 0; i < 4; i++){
		if(p1.code[i] == p2.code[i] && p1.code[i] == '1'){
			flag = 1;
		}
	}
	if(flag == 1)
		return(1);

	// when the line is partially inside and outside of the window
	return(2);
}

PT resetEndPoint(PT p1, PT p2){
	int x, y;
	float m, k;
	PT temp;
	if(p1.code[3] == '1')
		x = 150;
	if(p1.code[2] == '1')
		x = 450;

	if(p1.code[2] == '1' || p1.code[3] == '1'){
		m = (float) (p2.y - p1.y) / (p2.x - p1.x);
		k = (float) (p1.y + (x - p1.x) * m);

		temp.x = x;
		temp.y = k;
		for(int i = 0; i < 4; i++)
			temp.code[i] = p1.code[i];

		if(temp.x >= 100 && temp.y <= 350)
			return(temp);
	}

	if(p1.code[0] == '1')
		y = 100;
	if(p1.code[1] == '1')
		y = 350;

	if(p1.code[0] == '1' || p1.code[1] == '1'){
		m = (float)(p2.y - p1.y) / (p2.x - p1.x);
		k = (float) (p1.x + (y - p1.y) * m);

		temp.x = k;
		temp.y = y;

		for(int i = 0; i < 4; i++){
			temp.code[i] = p1.code[i];
		}
		return temp;
	}
	else
		return(p1);

}

int main(){
	int gd = DETECT;
	int gm = 0;
	initgraph(&gd, &gm, "");

	PT p1, p2, ptemp, p3, p4;
	puts("Enter two end points for the line:");
	printf("(x1, y1): ");
	scanf("%d %d", &p1.x, &p1.y);
	printf("(x2, y2): ");
	scanf("%d %d", &p2.x, &p2.y);

	drawWindow(); // drawing window
	delay(500);  // delay 1 second for next drawing

	drawLine(p1, p2); // drawing line
	delay(500);    // delay 3 seconds for clear the window screen

	cleardevice();
	delay(500);

	p1 = setCode(p1);
	p2 = setCode(p2);

	int v = visibility(p1, p2);
	printf("%d", v);
	delay(500);

	switch(v){
	case 0:
		drawWindow();
		delay(500);
		drawLine(p1, p2);
		break;
	case 1:
		drawWindow();
		delay(500);
		break;
	case 2:
		p3 = resetEndPoint(p1, p2);
		p4 = resetEndPoint(p2, p1);

		drawWindow();
		delay(500);

		drawLine(p3, p4);
		delay(500);
		break;
	}


	getch();
	return 0;
}

/*

100 100
400 300

*/
