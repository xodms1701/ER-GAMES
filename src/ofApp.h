#pragma once

#include "ofxGui.h"
#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void start_rh(int x, int y, int button);
	void start_sa(int key);

	ofTrueTypeFont font;
	ofImage name;
	ofImage name_b;
	ofImage title;
	ofImage menu;
	ofImage start_btn;
	ofImage exit_btn;
	ofImage game_2;
	ofImage game_3;
	ofImage how_btn;
	ofImage menu2;
	ofImage back_btn;
	ofImage ask;
	ofImage firsthorse;
	ofImage secondhorse;
	ofImage thirdhorse;
	ofImage fourthhorse;
	ofImage fifthhorse;
	ofImage horse_info;
	ofImage horse_ask;
	ofImage select;
	ofImage next_btn;
	ofImage rh_Info;
	ofImage sv_Info;
	ofImage mn_txt, mn_0, mn_1, mn_2, mn_3, mn_4, mn_5, mn_6, mn_7, mn_8, mn_9;
	ofImage arrow;
	ofImage betting;
	ofImage wait;
	ofImage horse_result;
	ofImage horse_wtxt;
	ofImage horse_ltxt;
	ofImage horse_over;
	ofImage save_btn;
	ofImage keyboard;
	ofImage game_over;
	int ypos[5] = { 0 };
	int x_s[5], y_s[5];
	int xx = 65;

	int ypost[5] = { 0 };
	int x_t[5], y_t[5];
	int xt = 785;

	int player_1y[10] = { 0 };
	int player_1xs[10], player_1ys[10];
	int player_2y[10] = { 0 };
	int player_2xs[10], player_2ys[10];


	int stage = 0;

	ofImage star;
	ofImage player;
	ofImage player2; 
	ofImage star_score;
	ofImage press_enter;
	ofImage stuck;
	ofImage star_space;
	ofImage galaga_space;
	ofImage done_btn;
	ofImage q, w, e, r, t, y, u, i, o, p, a, s, d, f, g, h, j, k, l, z, x, c, v, b, n, m;

	ofImage sun;
	ofImage sd_title;
	ofImage rh_title;
	ofImage sd_press;
	ofImage rh_press;
	ofImage message;
	ofImage gif;
	ofImage winner_1;
	ofImage winner_2;
	ofImage horse_name[5];

	int hx[5] = {35,};

	int horse_num;
	int fontsize = 100;
	int horse_anum;

	int start;
	int money;
	int temp = 0;
	int is = 0;
	int temp2 = 0;
	int xb;
	int bet;
	char naming[4];
	int as;
	int bk = 0;
	int star_jum = 0;
	int jo = 0;
	char* r_name[5];
	char* score[5];



	void mousePressed(int x, int y, int button);
	void keyPressed(int key);
};