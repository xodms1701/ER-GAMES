#include "ofApp.h"
#include <math.h>
#include <time.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//start변수는 0이면 첫화면, 1이면 게임시작, 2이면 갤러그 선택, 3이면 별피하기, 4이면 경마게임, 5이면 갤러그 게임방법, 6이면 별피하기, 7이면 경마게임
//8이면 갤러그 게임시작, 9이면 별피하기 시작, 10이면 경마게임 시작


//--------------------------------------------------------------
void ofApp::setup() {
	start = 0;
	money = 1000;
	bet = 100;
	temp = 0;

	ofSetBackgroundColor(0, 0, 0); //배경 흰색
	title.load("Untitled.jpg");
	start_btn.load("start_btn.jpg");
	exit_btn.load("exit_btn.jpg");
	name.load("name.jpg");
	name_b.load("name_b.jpg");

	game_2.load("star_avoid.jpg");
	game_3.load("riding_horse.jpg");

	menu.load("menu.jpg");
	menu2.load("menu2.jpg");

	how_btn.load("how_btn.jpg");
	back_btn.load("back_btn.jpg");
	ask.load("ask.jpg");
	font.load("koverwatch.ttf", fontsize);

	firsthorse.load("firsthorse.jpg");
	secondhorse.load("secondhorse.jpg");
	thirdhorse.load("thirdhorse.jpg");
	fourthhorse.load("fourthhorse.jpg");
	fifthhorse.load("fifthhorse.jpg");

	horse_info.load("horse_info.jpg");

	horse_ask.load("horse_ask.jpg");
	select.load("select.jpg");
	next_btn.load("next_btn.jpg");
	rh_Info.load("rh_info.jpg");
	sv_Info.load("sv_info.jpg");

	mn_txt.load("mn_txt.jpg");
	mn_0.load("mn_0.jpg");
	mn_1.load("mn_1.jpg");
	mn_2.load("mn_2.jpg");
	mn_3.load("mn_3.jpg");
	mn_4.load("mn_4.jpg");
	mn_5.load("mn_5.jpg");
	mn_6.load("mn_6.jpg");
	mn_7.load("mn_7.jpg");
	mn_8.load("mn_8.jpg");
	mn_9.load("mn_9.jpg");

	arrow.load("arrow.jpg");
	betting.load("betting.jpg");
	wait.load("wait.jpg");
	horse_result.load("horse_result.jpg");
	horse_wtxt.load("horse_txt.jpg");
	horse_ltxt.load("horse_txt.jpg");

	horse_over.load("horse_over.jpg");
	save_btn.load("save_btn.jpg");

	keyboard.load("keyboard.jpg");

	star.load("star.png");
	player.load("player.png");
	player2.load("player.png");
	star_score.load("star_score.png");
	game_over.load("horse_over.jpg");

	horse_name[0].load("oh.jpg");
	horse_name[1].load("th.jpg");
	horse_name[2].load("thh.jpg");
	horse_name[3].load("fh.jpg");
	horse_name[4].load("fhh.jpg");

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 5; i++) {
		x_s[i] = (rand() % 7 + 1) * 100;
		y_s[i] = rand() % 5 + 1;
		x_t[i] = (rand() % 7 + 1) * 100;
		y_t[i] = rand() % 5 + 1;
	}
	for (int i = 0; i < 10; i++) {
		player_1xs[i] = (rand() % 7 + 1) * 100;
		player_1ys[i] = rand() % 5 + 1;
		player_2xs[i] = (rand() % 7 + 1) * 100+720;
		player_2ys[i] = rand() % 5 + 1+720;
	}
	press_enter.load("press_1_2.jpg");
	stuck.load("stuck.png");
	star_space.load("star_space.jpg");
	done_btn.load("done_btn.jpg");
	q.load("q.jpg");
	w.load("w.jpg");
	e.load("e.jpg");
	r.load("r.jpg");
	t.load("t.jpg");
	y.load("y.jpg");
	u.load("u.jpg");
	i.load("i.jpg");
	o.load("o.jpg");
	a.load("a.jpg");
	s.load("s.jpg");
	d.load("d.jpg");
	f.load("f.jpg");
	g.load("g.jpg");
	h.load("h.jpg");
	j.load("j.jpg");
	k.load("k.jpg");
	l.load("l.jpg");
	z.load("z.jpg");
	x.load("x.jpg");
	c.load("c.jpg");
	v.load("v.jpg");
	b.load("b.jpg");
	n.load("n.jpg");
	m.load("m.jpg");
	sun.load("sun.jpg");

	sd_title.load("sd_title.jpg");
	rh_title.load("rh_title.jpg");

	sd_press.load("sd_press.jpg");
	rh_press.load("rh_press.jpg");

	message.load("message.jpg");
	gif.load("anigif.gif");
	winner_1.load("winner_1.jpg");
	winner_2.load("winner_2.jpg");
}

//--------------------------------------------------------------
void ofApp::update() {
	if (start == 4) {
		if (xb == 1) {
			Sleep(10);
			if (stage == 0) {
				for (int i = 0; i < 5; i++) {
					ypos[i] += y_s[i];
					ypost[i] += y_t[i];
					if (ypos[i] > ofGetHeight() - 55) {
						ypos[i] = 0;
						x_s[i] = (rand() % 7 + 1) * 100;
						y_s[i] = rand() % 5 + 1;
					}
					if (ypost[i] > ofGetHeight() - 55) {
						ypost[i] = 0;
						x_t[i] = (rand() % 7 + 1) * 100;
						y_t[i] = rand() % 5 + 1;

					}
				}
				if (star_jum > 100) stage++;
			}
			else if (stage == 1) {
				for (int i = 0; i < 5; i++) {
					ypos[i] += y_s[i];
					ypost[i] += y_t[i];
					if (ypos[i] > ofGetHeight() - 55) {
						ypos[i] = 0;
						x_s[i] = (rand() % 12 + 1) * 55;
						y_s[i] = rand() % 6 + 2;
					}
					if (ypost[i] > ofGetHeight() - 55) {
						ypost[i] = 0;
						x_t[i] = (rand() % 12 + 1) * 55;
						y_t[i] = rand() % 6 + 2;
					}
				}
				if (star_jum > 200) stage++;
			}
			else if (stage == 2) {
				for (int i = 0; i < 5; i++) {
					ypos[i] += y_s[i];
					ypost[i] += y_t[i];
					if (ypos[i] > ofGetHeight() - 55) {
						ypos[i] = 0;
						x_s[i] = (rand() % 12 + 1) * 55;
						y_s[i] = rand() % 7 + 3;
					}
					if (ypost[i] > ofGetHeight() - 55) {
						ypost[i] = 0;
						x_t[i] = (rand() % 12 + 1) * 55;
						y_t[i] = rand() % 7 + 3;
					}
				}
				if (star_jum > 300) stage++;
			}
			else if (stage == 3) {
				for (int i = 0; i < 5; i++) {
					ypos[i] += y_s[i];
					ypost[i] += y_t[i];
					if (ypos[i] > ofGetHeight() - 55) {
						ypos[i] = 0;
						x_s[i] = (rand() % 12 + 1) * 55;
						y_s[i] = rand() % 8 + 4;
					}
					if (ypost[i] > ofGetHeight() - 55) {
						ypost[i] = 0;
						x_t[i] = (rand() % 12 + 1) * 55;
						y_t[i] = rand() % 8 + 4;
					}
				}
				if (star_jum > 300) stage++;
			}
			else if (stage == 4) {
				for (int i = 0; i < 5; i++) {
					ypos[i] += y_s[i];
					ypost[i] += y_t[i];
					if (ypos[i] > ofGetHeight() - 55) {
						ypos[i] = 0;
						x_s[i] = (rand() % 12 + 1) * 55;
						y_s[i] = rand() % 9 + 5;
					}
					if (ypost[i] > ofGetHeight() - 55) {
						ypost[i] = 0;
						x_t[i] = (rand() % 12 + 1) * 55;
						y_t[i] = rand() % 9 + 5;
					}
				}
				if (star_jum > 400) stage++;
			}
			else if (stage == 5) {
				for (int i = 0; i < 5; i++) {
					ypos[i] += y_s[i];
					ypost[i] += y_t[i];
					if (ypos[i] > ofGetHeight() - 55) {
						ypos[i] = 0;
						x_s[i] = (rand() % 12 + 1) * 55;
						y_s[i] = rand() % 10 + 6;
					}
					if (ypost[i] > ofGetHeight() - 55) {
						ypost[i] = 0;
						x_t[i] = (rand() % 12 + 1) * 55;
						y_t[i] = rand() % 10 + 6;
					}
				}
			}
		}
		else if (xb == 3) {
			Sleep(10);
			for (int i = 0; i < 10; i++) {
				player_1y[i] += player_1ys[i];
				player_2y[i] += player_2ys[i];
				if (player_1y[i] > ofGetHeight() - 55) {
					player_1y[i] = 0;
					player_1xs[i] = (rand() %12 + 1) * 55;
					player_1ys[i] = rand() % 8 + 1;
				}
				if (player_2y[i] > ofGetHeight() - 55) {
					player_2y[i] = 0;
					player_2xs[i] = (rand() % 12 + 1) * 55+720;
					player_2ys[i] = rand() % 8 + 1;
				}
			}
		}
	}

	if (start == 10) {
		Sleep(10);
		for (int i = 0; i < 5; i++) {
			if (hx[i] < ofGetWidth() - 70) {
				hx[i] += rand() % 10 + 1;
			}
			else {
				start = 11;
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	menu2.draw(0, 0, 1920, 1080);
	name.draw(1780, 45);
	if (start == 0) {//게임 시작화면
		title.draw(310, 35);
		start_btn.draw(775, 500);
		exit_btn.draw(775, 700);
	}
	else if (start == 1) {//게임 선택화면
		ask.draw(310, 35);
		game_2.draw(775, 550);
		game_3.draw(775, 700);
		back_btn.draw(775, 850);
	}
	else if (start == 2) {//별피하기 시작화면
		xb = 0;
		stage = 0;
		star_jum = 0;
		for (int i = 0; i < 5; i++) {
			ypos[i] = 0;
			ypost[i] = 0;
			x_s[i] = (rand() % 7 + 1) * 100;
			y_s[i] = rand() % 5 + 1;
			x_t[i] = (rand() % 7 + 1) * 100;
			y_t[i] = rand() % 5 + 1;
		}
		sd_title.draw(310, 35);
		start_btn.draw(775, 500);
		how_btn.draw(775, 650);
		back_btn.draw(775, 800);
	}
	else if (start == 3) {//별피하기 게임방법 화면
		sv_Info.draw(35, 85);
		back_btn.draw(775, 800);
	}
	else if (start == 4) {//별피하기 게임화면
		if (xb == 0) {
			press_enter.draw(680, 440);
		}
		else if (xb == 1) {
			star_space.draw(45, 45); //700, 990
			for (int j = 0; j < 5; j++) {
				if (ypos[j] <= ofGetHeight()-95) {
					star.draw(x_s[j], ypos[j], 30, 30);
					if (abs(x_s[j] - xx) <= 15 && abs(ofGetHeight() - 95 - ypos[j]) <= 20) {
						star_jum += 10;
						x_s[j] = (rand() % 7 + 1) * 100;
						ypos[j] = 55;
					}
				}
				if (ypost[j] <= ofGetHeight() - 95) {
					stuck.draw(x_t[j], ypost[j], 30, 30);
					if (abs(x_t[j] - xx) <= 15 && abs(ofGetHeight() - 95 - ypost[j]) <= 20) {
						xb = 2;
					}
				}
				player.draw(xx, ofGetHeight() - 95, 30, 30);
			}
			
			
			//score---------------
			star_score.draw(1235, 55);
			int lala = star_jum;
			for (is = 0; lala >= 10; is++) {
				lala = lala / 10;
			}
			int tm3 = star_jum;
			for (int j = is + 1; j > 0; j--) {
				switch (tm3 % 10) {
				case 0:
					mn_0.draw(1335 + 95 * j, 55);
					break;
				case 1:
					mn_1.draw(1335 + 95 * j, 55);
					break;
				case 2:
					mn_2.draw(1335 + 95 * j, 55);
					break;
				case 3:
					mn_3.draw(1335 + 95 * j, 55);
					break;
				case 4:
					mn_4.draw(1335 + 95 * j, 55);
					break;
				case 5:
					mn_5.draw(1335 + 95 * j, 55);
					break;
				case 6:
					mn_6.draw(1335 + 95 * j, 55);
					break;
				case 7:
					mn_7.draw(1335 + 95 * j, 55);
					break;
				case 8:
					mn_8.draw(1335 + 95 * j, 55);
					break;
				case 9:
					mn_9.draw(1335 + 95 * j, 55);
					break;
				}
				tm3 = tm3 / 10;
			}
		}
		else if (xb == 2) {
			xx = 65;
			game_over.draw(710, 300);
			sd_press.draw(415, 900);
			int lala = star_jum;
			for (is = 0; lala >= 10; is++) {
				lala = lala / 10;
			}
			int tm3 = star_jum;
			for (int j = is + 1; j > 0; j--) {
				switch (tm3 % 10) {
				case 0:
					mn_0.draw(680 + 95 * j, 580);
					break;
				case 1:
					mn_1.draw(680 + 95 * j, 580);
					break;
				case 2:
					mn_2.draw(680 + 95 * j, 580);
					break;
				case 3:
					mn_3.draw(680 + 95 * j, 580);
					break;
				case 4:
					mn_4.draw(680 + 95 * j, 580);
					break;
				case 5:
					mn_5.draw(680 + 95 * j, 580);
					break;
				case 6:
					mn_6.draw(680 + 95 * j, 580);
					break;
				case 7:
					mn_7.draw(680 + 95 * j, 580);
					break;
				case 8:
					mn_8.draw(680 + 95 * j, 580);
					break;
				case 9:
					mn_9.draw(680 + 95 * j, 580);
					break;
				}
				tm3 = tm3 / 10;
			}
		}
		else if (xb == 3) {
			star_space.draw(45, 45); //700, 990
			star_space.draw(765, 45);
			for (int j = 0; j < 10; j++) {
				if (player_1y[j] <= ofGetHeight() - 95) {
					stuck.draw(player_1xs[j], player_1y[j], 30, 30);
					if (abs(player_1xs[j] - xx) <= 15 && abs(ofGetHeight() - 95 - player_1y[j]) <= 20) {
						xb = 4;
					}
				}
				player.draw(xx, ofGetHeight() - 95, 30, 30);
			}
			for (int j = 0; j <10; j++) {
				if (player_2y[j] <= ofGetHeight() - 95) {
					stuck.draw(player_2xs[j], player_2y[j], 30, 30);
					if (abs(player_2xs[j] - xt) <= 15 && abs(ofGetHeight() - 95 - player_2y[j]) <= 20) {
						xb = 5;
					}
				}
				player2.draw(xt, ofGetHeight() - 95, 30, 30);
			}
		}
		else if (xb == 4) {
			for (int i = 0; i < 10; i++) {
				player_1xs[i] = (rand() % 7 + 1) * 100;
				player_1ys[i] = rand() % 5 + 1;
				player_2xs[i] = (rand() % 7 + 1) * 100 + 720;
				player_2ys[i] = rand() % 5 + 1 + 720;
			}
			xx = 65;
			xt = 785;
			winner_2.draw(845,300);
			back_btn.draw(775, 850);
		}
		else if (xb == 5) {
			for (int i = 0; i < 10; i++) {
				player_1xs[i] = (rand() % 7 + 1) * 100;
				player_1ys[i] = rand() % 5 + 1;
				player_2xs[i] = (rand() % 7 + 1) * 100 + 720;
				player_2ys[i] = rand() % 5 + 1 + 720;
			}
			xx = 65;
			xt = 785;
			winner_1.draw(845,300);
			back_btn.draw(775, 850);
		}
	}
	else if (start == 5) {//경마게임 시작하면
		money = 1000;
		rh_title.draw(310, 35);
		start_btn.draw(775, 500);
		how_btn.draw(775, 650);
		back_btn.draw(775, 800);
	}
	else if (start == 6) {//경마게임 게임방법 화면
		rh_Info.draw(35, 85);
		back_btn.draw(775, 800);
	}

	else if (start == 7) {//경마게임 게임화면1
		menu2.draw(0, 0, 1920, 1080);
		name.draw(1780, 45);
		horse_ask.draw(310, 35);
		horse_info.draw(220, 235);
	}
	else if (start == 8) {//경마게임 게임화면2
		switch (horse_num) {
		case 1:
			firsthorse.draw(740, 85, 400, 400);
			break;
		case 2:
			secondhorse.draw(740, 85, 400, 400);
			break;
		case 3:
			thirdhorse.draw(740, 85, 400, 400);
			break;
		case 4:
			fourthhorse.draw(740, 85, 400, 400);
			break;
		case 5:
			fifthhorse.draw(740, 85, 400, 400);
			break;
		}
		select.draw(650, 600);
		back_btn.draw(500, 800);
		next_btn.draw(950, 800);
	}
	else if (start == 9) {//경마게임 게임화면3
		mn_txt.draw(420, 150);
		temp = money;
		for (is = 0; temp >= 10; is++) {
			temp = temp / 10;
		}
		int tm = money;
		for (int j = is + 1; j > 0; j--) {
			switch (tm % 10) {
			case 0:
				mn_0.draw(825 + 95 * j, 150);
				break;
			case 1:
				mn_1.draw(825 + 95 * j, 150);
				break;
			case 2:
				mn_2.draw(825 + 95 * j, 150);
				break;
			case 3:
				mn_3.draw(825 + 95 * j, 150);
				break;
			case 4:
				mn_4.draw(825 + 95 * j, 150);
				break;
			case 5:
				mn_5.draw(825 + 95 * j, 150);
				break;
			case 6:
				mn_6.draw(825 + 95 * j, 150);
				break;
			case 7:
				mn_7.draw(825 + 95 * j, 150);
				break;
			case 8:
				mn_8.draw(825 + 95 * j, 150);
				break;
			case 9:
				mn_9.draw(825 + 95 * j, 150);
				break;
			}
			tm = tm / 10;
		}

		betting.draw(420, 400);
		int tm2 = bet;
		if (bet > money) {
			bet = money;
		}
		else if (bet < 0) {
			bet = 0;
		}
		temp = bet;
		for (is = 0; temp >= 10; is++) {
			temp = temp / 10;
		}
		for (int j = is + 1; j > 0; j--) {
			switch (tm2 % 10) {
			case 0:
				mn_0.draw(825 + 95 * j, 400);
				break;
			case 1:
				mn_1.draw(825 + 95 * j, 400);
				break;
			case 2:
				mn_2.draw(825 + 95 * j, 400);
				break;
			case 3:
				mn_3.draw(825 + 95 * j, 400);
				break;
			case 4:
				mn_4.draw(825 + 95 * j, 400);
				break;
			case 5:
				mn_5.draw(825 + 95 * j, 400);
				break;
			case 6:
				mn_6.draw(825 + 95 * j, 400);
				break;
			case 7:
				mn_7.draw(825 + 95 * j, 400);
				break;
			case 8:
				mn_8.draw(825 + 95 * j, 400);
				break;
			case 9:
				mn_9.draw(825 + 95 * j, 400);
				break;
			}
			tm2 = tm2 / 10;
		}
		arrow.draw(1340, 400);
		back_btn.draw(500, 800);
		next_btn.draw(950, 800);
	}
	else if (start == 10) {//경마게임 화면 4
		firsthorse.draw(hx[0], 100,50,50);
		secondhorse.draw(hx[1], 200, 50, 50);
		thirdhorse.draw(hx[2], 300, 50, 50);
		fourthhorse.draw(hx[3], 400, 50, 50);
		fifthhorse.draw(hx[4], 500, 50, 50);

		wait.draw(460, 600);
	}
	else if (start == 11) {
		horse_result.draw(460, 200);
		next_btn.draw(750, 800);
		for (int i = 0; i < 5; i++) {
			hx[i] = 0;
		}
	}
	else if (start == 12) {
		money -= bet;
		srand((unsigned int)time(NULL));

		horse_anum = rand() % 15 + 1;
		if (horse_anum <= 5) {
			horse_anum = 1;
		}
		else if (horse_anum <= 9) {
			horse_anum = 2;
		}
		else if (horse_anum <= 12) {
			horse_anum = 3;
		}
		else if (horse_anum <= 14) {
			horse_anum = 4;
		}
		else {
			horse_anum = 5;
		}

		if (horse_num == horse_anum) { //맞춤
			start = 13;
		}
		else {				//틀림
			start = 14;
		}
	}
	else if (start == 13) {
		Sleep(100);
		switch (horse_num) {
		case 1:
			money += bet * 2;
			break;
		case 2:
			money += bet * 3;
			break;
		case 3:
			money += bet * 5;
			break;
		case 4:
			money += bet * 10;
			break;
		case 5:
			money += bet * 20;
		}
		bet = 0;
		horse_wtxt.draw(710, 150);
		horse_name[horse_anum - 1].draw(730, 213);
		horse_name[horse_num - 1].draw(900, 335);
		exit_btn.draw(553, 800);
		next_btn.draw(1003, 800);
	}
	else if (start == 14) {
		Sleep(100);
		horse_ltxt.draw(710, 150);
		if (money == 0) {
			start = 15;
		}
		bet = 0;
		horse_name[horse_anum - 1].draw(730, 213);
		horse_name[horse_num - 1].draw(900, 335);
		exit_btn.draw(553, 800);
		next_btn.draw(1003, 800);
	}
	else if (start == 15) {
		horse_over.draw(710, 150);
		rh_press.draw(688, 700);
		temp = money;
		for (is = 0; temp >= 10; is++) {
			temp = temp / 10;
		}
		int tm = money;
		for (int j = is + 1; j > 0; j--) {
			switch (tm % 10) {
			case 0:
				mn_0.draw(625 + 95 * j, 450);
				break;
			case 1:
				mn_1.draw(625 + 95 * j, 450);
				break;
			case 2:
				mn_2.draw(625 + 95 * j, 450);
				break;
			case 3:
				mn_3.draw(625 + 95 * j, 450);
				break;
			case 4:
				mn_4.draw(625 + 95 * j, 450);
				break;
			case 5:
				mn_5.draw(625 + 95 * j, 450);
				break;
			case 6:
				mn_6.draw(625 + 95 * j, 450);
				break;
			case 7:
				mn_7.draw(625 + 95 * j, 450);
				break;
			case 8:
				mn_8.draw(625 + 95 * j, 450);
				break;
			case 9:
				mn_9.draw(625 + 95 * j, 450);
				break;
			}
			tm = tm / 10;
		}
		exit_btn.draw(778, 800);
	}
	else if (start == 16) { //star_drop save
		message.draw(725, 255);
		done_btn.draw(45, 315);
		keyboard.draw(45, 535);
		for (int io = 0; io < 4; io++) {
			switch (naming[io]) {
			case 'Q':
				q.draw(725 + 95 * io, 35);
				break;
			case 'W':
				w.draw(725 + 95 * io, 35);
				break;
			case 'E':
				e.draw(725 + 95 * io, 35);
				break;
			case 'R':
				r.draw(725 + 95 * io, 35);
				break;
			case 'T':
				t.draw(725 + 95 * io, 35);
				break;
			case 'Y':
				y.draw(725 + 95 * io, 35);
				break;
			case 'U':
				u.draw(725 + 95 * io, 35);
				break;
			case 'I':
				i.draw(725 + 95 * io, 35);
				break;
			case 'O':
				o.draw(725 + 95 * io, 35);
				break;
			case 'P':
				p.draw(725 + 95 * io, 35);
				break;
			case 'A':
				a.draw(725 + 95 * io, 35);
				break;
			case 'S':
				s.draw(725 + 95 * io, 35);
				break;
			case 'D':
				d.draw(725 + 95 * io, 35);
				break;
			case 'F':
				f.draw(725 + 95 * io, 35);
				break;
			case 'G':
				g.draw(725 + 95 * io, 35);
				break;
			case 'H':
				h.draw(725 + 95 * io, 35);
				break;
			case 'J':
				j.draw(725 + 95 * io, 35);
				break;
			case 'K':
				k.draw(725 + 95 * io, 35);
				break;
			case 'L':
				l.draw(725 + 95 * io, 35);
				break;
			case 'Z':
				z.draw(725 + 95 * io, 35);
				break;
			case 'X':
				x.draw(725 + 95 * io, 35);
				break;
			case 'C':
				c.draw(725 + 95 * io, 35);
				break;
			case 'V':
				v.draw(725 + 95 * io, 35);
				break;
			case 'B':
				b.draw(725 + 95 * io, 35);
				break;
			case 'N':
				n.draw(725 + 95 * io, 35);
				break;
			case 'M':
				m.draw(725 + 95 * io, 35);
				break;
			}
		}
	}
	else if (start == 17) {
		message.draw(725, 255);
		done_btn.draw(45, 315);
		keyboard.draw(45, 535);
		for (int io = 0; io < 4; io++) {
			switch (naming[io]) {
			case 'Q':
				q.draw(725 + 95 * io, 35);
				break;
			case 'W':
				w.draw(725 + 95 * io, 35);
				break;
			case 'E':
				e.draw(725 + 95 * io, 35);
				break;
			case 'R':
				r.draw(725 + 95 * io, 35);
				break;
			case 'T':
				t.draw(725 + 95 * io, 35);
				break;
			case 'Y':
				y.draw(725 + 95 * io, 35);
				break;
			case 'U':
				u.draw(725 + 95 * io, 35);
				break;
			case 'I':
				i.draw(725 + 95 * io, 35);
				break;
			case 'O':
				o.draw(725 + 95 * io, 35);
				break;
			case 'P':
				p.draw(725 + 95 * io, 35);
				break;
			case 'A':
				a.draw(725 + 95 * io, 35);
				break;
			case 'S':
				s.draw(725 + 95 * io, 35);
				break;
			case 'D':
				d.draw(725 + 95 * io, 35);
				break;
			case 'F':
				f.draw(725 + 95 * io, 35);
				break;
			case 'G':
				g.draw(725 + 95 * io, 35);
				break;
			case 'H':
				h.draw(725 + 95 * io, 35);
				break;
			case 'J':
				j.draw(725 + 95 * io, 35);
				break;
			case 'K':
				k.draw(725 + 95 * io, 35);
				break;
			case 'L':
				l.draw(725 + 95 * io, 35);
				break;
			case 'Z':
				z.draw(725 + 95 * io, 35);
				break;
			case 'X':
				x.draw(725 + 95 * io, 35);
				break;
			case 'C':
				c.draw(725 + 95 * io, 35);
				break;
			case 'V':
				v.draw(725 + 95 * io, 35);
				break;
			case 'B':
				b.draw(725 + 95 * io, 35);
				break;
			case 'N':
				n.draw(725 + 95 * io, 35);
				break;
			case 'M':
				m.draw(725 + 95 * io, 35);
				break;
			}
		}
	}
	else if (start == 18) {
		menu.draw(0, 0);
		name_b.draw(1780, 45);
		next_btn.draw(775, 700);
	}
	else if (start == 19) {
		menu.draw(0, 0);
		name_b.draw(1780, 45);
		font.drawString("Save Success", 680, 280);
		next_btn.draw(775, 700);
	}

}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	//첫화면
	start_rh(x, y, button);
}

void ofApp::keyPressed(int key)
{
	// 키보드가 눌렸을 시 호출되는 부분
	// int key 값으로 어느 키가 눌렸는지를 판별
	start_sa(key);
}

//------------------------------------------------------------------
void ofApp::start_rh(int x, int y, int button) {
	if ((x >= 775 && x <= 1140) && (y >= 500 && y <= 599) && button == 0 && start == 0) { //첫 화면에서 게임스타트
		start = 1;
	}
	else if ((x >= 775 && x <= 1140) && (y >= 700 && y <= 799) && button == 0 && start == 0) { //나가기
		ofExit();
	}
	//choose game
	else if ((x >= 775 && x <= 1141) && (y >= 550 && y <= 649) && button == 0 && start == 1) {//별게임시작화면
		start = 2;
	}
	else if ((x >= 775 && x <= 1141) && (y >= 700 && y <= 799) && button == 0 && start == 1) {//경마게임 시작화면
		start = 5;
	}
	else if ((x >= 775 && x <= 1141) && (y >= 850 && y <= 949) && button == 0 && start == 1) {//back 버튼
		start = 0;
	}
	//--------------------별피하기-----------------
	else if ((x >= 775 && x <= 1141) && (y >= 650 && y <= 745) && button == 0 && start == 2) {//방법 버튼
		start = 3;
	}
	else if ((x >= 775 && x <= 1141) && (y >= 800 && y <= 899) && button == 0 && start == 3) {	//방법 화면 내 back버튼
		start = 2;
	}
	else if ((x >= 775 && x <= 1141) && (y >= 500 && y <= 599) && button == 0 && start == 2) {//게임 시작
		start = 4;
	}
	else if ((x >= 775 && x <= 1141) && (y >= 800 && y <= 899) && button == 0 && start == 2) {//back
		start = 1;
	}
	else if ((x >= 775 && x <= 1141) && (y >= 850 && y <= 949) && button == 0 && start == 4 && xb == 4 || xb == 5) {
		start = 2;
	}
	//---------------경마게임--------------
	else if ((x >= 775 && x <= 1141) && (y >= 650 && y <= 745) && button == 0 && start == 5) {//방법 버튼
		start = 6;
	}
	else if ((x >= 775 && x <= 1141) && (y >= 800 && y <= 899) && button == 0 && start == 6) {	//방법 화면 내 back 버튼
		start = 5;
	}
	else if ((x >= 775 && x <= 1141) && (y >= 500 && y <= 599) && button == 0 && start == 5) {	//게임 시작
		start = 7;
	}
	else if ((x >= 775 && x <= 1141) && (y >= 800 && y <= 899) && button == 0 && start == 5) {	//back 버튼
		start = 1;
	}
	//---------------말 선택화면-------------------
	else if ((x >= 220 && x <= 1720) && (y >= 235 && y <= 400) && button == 0 && start == 7) {
		start = 8;
		horse_num = 1;
	}
	else if ((x >= 220 && x <= 1720) && (y >= 401 && y <= 565) && button == 0 && start == 7) {
		start = 8;
		horse_num = 2;
	}
	else if ((x >= 220 && x <= 1720) && (y >= 566 && y <= 730) && button == 0 && start == 7) {
		start = 8;
		horse_num = 3;
	}
	else if ((x >= 220 && x <= 1720) && (y >= 731 && y <= 895) && button == 0 && start == 7) {
		start = 8;
		horse_num = 4;
	}
	else if ((x >= 220 && x <= 1720) && (y >= 896 && y <= 1060) && button == 0 && start == 7) {
		start = 8;
		horse_num = 5;
	}
	//---------------선택 완료 화면-------------
	else if ((x >= 500 && x <= 866) && (y >= 800 && y <= 899) && button == 0 && start == 8) {
		start = 7;
	}
	else if ((x >= 950 && x <= 1316) && (y >= 800 && y <= 899) && button == 0 && start == 8) {
		start = 9;
	}
	//-------------자본금, 베팅금 화면---------
	else if ((x >= 1320 && x <= 1520) && (y >= 400 && y <= 500) && button == 0 && start == 9) {
		bet += 10;
	}
	else if ((x >= 1320 && x <= 1520) && (y >= 501 && y <= 600) && button == 0 && start == 9) {
		bet -= 10;
	}
	else if ((x >= 500 && x <= 866) && (y >= 800 && y <= 899) && button == 0 && start == 9) { //back
		start = 8;
	}
	else if ((x >= 950 && x <= 1316) && (y >= 800 && y <= 899) && button == 0 && start == 9 && bet != 0) { //next
		start = 10;
	}
	//---------말 경기 후 넥스트버튼-------
	else if ((x >= 750 && x <= 1106) && (y >= 800 && y <= 899) && button == 0 && start == 11) {
		start = 12;
	}

	//----------------결과창---------------------
	else if ((x >= 500 && x <= 866) && (y >= 800 && y <= 899) && button == 0 && start == 13) { //exit
		start = 15;
	}
	else if ((x >= 950 && x <= 1316) && (y >= 800 && y <= 899) && button == 0 && start == 13) { //next
		start = 7;
	}

	else if ((x >= 500 && x <= 866) && (y >= 800 && y <= 899) && button == 0 && start == 14) { //exit
		start = 15;
	}
	else if ((x >= 950 && x <= 1316) && (y >= 800 && y <= 899) && button == 0 && start == 14) { //next
		start = 7;
	}
	//------------------------------------------------
	else if ((x >= 778 && x <= 1143) && (y >= 800 && y <= 899) && button == 0 && start == 15) { //exit
		start = 1;
		money = 1000;
		bet = 100;
	}
	else if (button == 0 && start == 16) { //star save
		naming[jo] = NULL;
		if (jo < 4) {
			if (y >= 567 && y <= 677) {
				if (x >= 77 && x <= 187) {
					naming[jo] = 'Q';
					jo++;
				}
				else if (x >= 259 && x <= 369) {
					naming[jo] = 'W';
					jo++;
				}
				else if (x >= 441 && x <= 551) {
					naming[jo] = 'E';
					jo++;
				}

				else if (x >= 623 && x <= 733) {
					naming[jo] = 'R';
					jo++;
				}
				else if (x >= 805 && x <= 915) {
					naming[jo] = 'T';
					jo++;
				}
				else if (x >= 987 && x <= 1097) {
					naming[jo] = 'Y';
					jo++;
				}
				else if (x >= 1169 && x <= 1279) {
					naming[jo] = 'U';
					jo++;
				}
				else if (x >= 1351 && x <= 1461) {
					naming[jo] = 'I';
					jo++;
				}
				else if (x >= 1533 && x <= 1643) {
					naming[jo] = 'O';
					jo++;
				}
				else if (x >= 1717 && x <= 1827) {
					naming[jo] = 'P';
					jo++;
				}
			}
			else if (y >= 732 && y <= 842) {
				if (x >= 92 && x <= 202) {
					naming[jo] = 'A';
					jo++;
				}
				else if (x >= 290 && x <= 400) {
					naming[jo] = 'S';
					jo++;
				}
				else if (x >= 488 && x <= 598) {
					naming[jo] = 'D';
					jo++;
				}
				else if (x >= 686 && x <= 796) {
					naming[jo] = 'F';
					jo++;
				}
				else if (x >= 884 && x <= 994) {
					naming[jo] = 'G';
					jo++;
				}
				else if (x >= 1082 && x <= 1192) {
					naming[jo] = 'H';
					jo++;
				}
				else if (x >= 1280 && x <= 1390) {
					naming[jo] = 'J';
					jo++;
				}
				else if (x >= 1478 && x <= 1588) {
					naming[jo] = 'K';
					jo++;
				}
				else if (x >= 1676 && x <= 1786) {
					naming[jo] = 'L';
					jo++;
				}
			}
			else if (y >= 895 && y <= 1005) {
				if (x >= 309 && x <= 419) {
					naming[jo] = 'Z';
					jo++;
				}
				else if (x >= 507 && x <= 617) {
					naming[jo] = 'X';
					jo++;
				}
				else if (x >= 705 && x <= 815) {
					naming[jo] = 'C';
					jo++;
				}
				else if (x >= 903 && x <= 1013) {
					naming[jo] = 'V';
					jo++;
				}
				else if (x >= 1101 && x <= 1211) {
					naming[jo] = 'B';
					jo++;
				}
				else if (x >= 1299 && x <= 1409) {
					naming[jo] = 'N';
					jo++;
				}
				else if (x >= 1497 && x <= 1607) {
					naming[jo] = 'M';
					jo++;
				}
				else if (x >= 1695 && x <= 1805) {
					naming[jo] = NULL;
					jo--;
				}
			}
		}
		if ((x >= 45 && x <= 1875) && (y >= 315 && y <= 515)) {
			ofstream out("star_drop_rank.txt", ios::app);

			if (out.is_open()) {
				out << naming << ":" << star_jum << "\n";
			}
			xb = 0;
			star_jum = 0;
			start = 18;
			jo = 0;

			// 입력파일을 input.txt라고 가정
			ifstream ifs("star_drop_rank.txt");

			// 라인문자열을 저장할 버퍼
			char line[255];

			if (!ifs) {
				cerr << "입력파일을 개방할 수가 없습니다." << endl;
			}
			is = 0;
			// 라인단위로 파일을 읽어내기
			while (ifs.getline(line, 255) && is<5)
			{
				// 방금읽은 문자열을 분리자 '/'로 먼저 분리
				char* token = strtok(line, ":");
				// 분리된 문자열이 존재하면 출력화일의 끝에 덧붙이기
				if (token)
					r_name[is] = token;
				token = strtok(NULL, "\n");
				if (token)
					score[is] = token;
				is++;
			}
			// 파일 닫기
			ifs.close();
		}
	}
	//----------------------------------------.
	else if (button == 0 && start == 17) { //horse save
		
		if (jo < 4) {
			naming[jo] = NULL;
			if (y >= 567 && y <= 677) {
				if (x >= 77 && x <= 187) {
					naming[jo] = 'Q';
					jo++;
				}
				else if (x >= 259 && x <= 369) {
					naming[jo] = 'W';
					jo++;
				}
				else if (x >= 441 && x <= 551) {
					naming[jo] = 'E';
					jo++;
				}

				else if (x >= 623 && x <= 733) {
					naming[jo] = 'R';
					jo++;
				}
				else if (x >= 805 && x <= 915) {
					naming[jo] = 'T';
					jo++;
				}
				else if (x >= 987 && x <= 1097) {
					naming[jo] = 'Y';
					jo++;
				}
				else if (x >= 1169 && x <= 1279) {
					naming[jo] = 'U';
					jo++;
				}
				else if (x >= 1351 && x <= 1461) {
					naming[jo] = 'I';
					jo++;
				}
				else if (x >= 1533 && x <= 1643) {
					naming[jo] = 'O';
					jo++;
				}
				else if (x >= 1717 && x <= 1827) {
					naming[jo] = 'P';
					jo++;
				}
			}
			else if (y >= 732 && y <= 842) {
				if (x >= 92 && x <= 202) {
					naming[jo] = 'A';
					jo++;
				}
				else if (x >= 290 && x <= 400) {
					naming[jo] = 'S';
					jo++;
				}
				else if (x >= 488 && x <= 598) {
					naming[jo] = 'D';
					jo++;
				}
				else if (x >= 686 && x <= 796) {
					naming[jo] = 'F';
					jo++;
				}
				else if (x >= 884 && x <= 994) {
					naming[jo] = 'G';
					jo++;
				}
				else if (x >= 1082 && x <= 1192) {
					naming[jo] = 'H';
					jo++;
				}
				else if (x >= 1280 && x <= 1390) {
					naming[jo] = 'J';
					jo++;
				}
				else if (x >= 1478 && x <= 1588) {
					naming[jo] = 'K';
					jo++;
				}
				else if (x >= 1676 && x <= 1786) {
					naming[jo] = 'L';
					jo++;
				}
			}
			else if (y >= 895 && y <= 1005) {
				if (x >= 309 && x <= 419) {
					naming[jo] = 'Z';
					jo++;
				}
				else if (x >= 507 && x <= 617) {
					naming[jo] = 'X';
					jo++;
				}
				else if (x >= 705 && x <= 815) {
					naming[jo] = 'C';
					jo++;
				}
				else if (x >= 903 && x <= 1013) {
					naming[jo] = 'V';
					jo++;
				}
				else if (x >= 1101 && x <= 1211) {
					naming[jo] = 'B';
					jo++;
				}
				else if (x >= 1299 && x <= 1409) {
					naming[jo] = 'N';
					jo++;
				}
				else if (x >= 1497 && x <= 1607) {
					naming[jo] = 'M';
					jo++;
				}
				else if (x >= 1695 && x <= 1805) {
					naming[jo] = NULL;
					jo--;
				}
			}
		}
		if ((x >= 45 && x <= 1875) && (y >= 315 && y <= 515)) {
			start = 19;
			jo = 0;
			// 파일 쓰기 준비
			ofstream out("horse_riding_rank.txt", ios::app);

			if (out.is_open()) {
				out << naming << ":" << money << "\n";
			}
		}

	}
	else if ((x >= 775 && x <= 1140) && (y >= 700 && y <= 799) && button == 0 && start >= 18 && start <= 19) {
		start = 1;
	}

}
void ofApp::start_sa(int key) {

	if (xb == 0 && start == 4 && key == 49) {
		xb = 1;
	}
	else if (xb == 0 && start == 4 && key == 50) {
		xb = 3;
	}
	
	else if (xb == 2 && start == 4 && key == 115) {
		start = 16;
		for (int i = 0; i < 4; i++) {
			naming[i] = NULL;
		}
		
	}else if (xb == 2 && start == 4 && key == 98) {
		start = 2;
	}
	if (start == 15 && key==115) {
		start = 17;
		for (int i = 0; i < 4; i++) {
			naming[i] = NULL;
		}
	}
	if (xb == 1 && key == OF_KEY_LEFT && xx >= 70) {
		xx -= 10;
	}
	if (xb == 1 && key == OF_KEY_RIGHT && xx <= 700) {
		xx += 10;
	}

	if (xb == 3 && key == 97 && xx >= 70) {
		xx -= 10;
	}
	if (xb == 3 && key == 100 && xx <= 700) {
		xx += 10;
	}

	if (xb == 3 && key == OF_KEY_LEFT && xt >= 780) {
		xt -= 10;
	}
	if (xb == 3 && key == OF_KEY_RIGHT && xt <= 1410) {
		xt += 10;
	}
}