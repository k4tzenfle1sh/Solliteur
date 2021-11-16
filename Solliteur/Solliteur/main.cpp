#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <string.h>
#include "variables.h"
#include <clocale>
using namespace std;

bool check_column(Main_Pattern mass[20][8], string house_leer[4], string null, int i, int j) {
	bool rezult = false;
	for (i; i < 20; i++) {
		if (i + 1 > 20) {
			if (mass[i][j].power != 0 && mass[i + 1][j].power != 0) {
				if (mass[i][j].power - mass[i + 1][j].power == 1) {
					if (mass[i][j].lear != null && mass[i + 1][j].lear != null) { //если карты вообще нет
						bool check = false;
						int A_count_leer = 0;
						int B_count_leer = 0;
						int count = 0;
						while (!check) {
							if (mass[i][j].lear == house_leer[count]) { //если масть карты и масть ячейки дома совпадают
								A_count_leer = count;
								check = true;
							}
							else {
								if (mass[i + 1][j].lear == house_leer[count]) { //если масть карты и масть ячейки дома совпадают
									B_count_leer = count;
									check = true;
								}
								else count++;
							}
						}
						if ((A_count_leer + B_count_leer) % 2 == 0)
							return rezult == true;
						else
							return rezult;
					}
				}
			}
		}
	}
}
bool check_free_deck(A_card A[2], Main_Pattern mass[20][8], string house_leer[4], string null, int k, int i, int j) {
	bool rezult = false;
	if (A[k].power != 0 && mass[i + 1][j].power == 0) {
		if (mass[i+1][j].power - A[k].power == 1) {
			if (A[k].lear != null && mass[i + 1][j].lear != null) { //если карты вообще нет
				bool check = false;
				int A_count_leer = 0;
				int B_count_leer = 0;
				int count = 0;
				while (!check) {
					if (A[k].lear == house_leer[count]) { //если масть карты и масть ячейки дома совпадают
						A_count_leer = count;
						check = true;
					}
					if (mass[i + 1][j].lear == house_leer[count]) { //если масть карты и масть ячейки дома совпадают
						B_count_leer = count;
						check = true;
					}
					else count++;
				}
				if ((A_count_leer + B_count_leer) % 2 == 0)
					return rezult = true;
				else
					return rezult;
			}
		}
	}
}
bool find_column(Main_Pattern mass[20][8], int count_free_column, Free_column free_column[5]) {
	bool rezult = false;
	int count;
	int j = 0;
	while (j < 8) {
		count = 0;
		for (int i = 0; i < 20; i++) {
			if (mass[i][j].power == 0)
				count++;
		}
		if (count == 20) {
			free_column[count_free_column].count = j;
			count_free_column++;
		}
		j++;
	}
	if (count_free_column != 0) return rezult = true;
	else return rezult;
}
int how_card(A_card A[2], Main_Pattern mass[20][8]) {
	bool check = false;
	int i = A[0].x,
		rezult = 1;
	while (!check) {
		if (mass[i + 1][A[0].y].power != 0) {
			rezult++;
			i++;
		}
		else
			check = true;
	}
	return rezult;
}
void clrscr()
{
	system("CLS");
}
bool card_is_exist(Main_Pattern mass[20][8], A_card A[2], string house_leer[4], int x) {
	bool rezult = false;
	if (x == 0) {
		//if ((A[0].power >= 1 && A[0].power <= 13) && ((A[0].lear == house_leer[0]) || (A[0].lear == house_leer[1]) || (A[0].lear == house_leer[2]) || (A[0].lear == house_leer[3])))
		if (A[0].power >= 1 && A[0].power <= 13)
			return rezult = true;
		else
			return rezult = false;
	}
	if (x == 1) {
		if ((A[1].power >= 1 && A[1].power <= 13) && ((A[1].lear == house_leer[0]) || (A[1].lear == house_leer[1]) || (A[1].lear == house_leer[2]) || (A[1].lear == house_leer[3])))
			return rezult = true;
		else
			return rezult = false;
	}
}
bool cheak_all_place(Main_Pattern mass[20][8], House sup_mass[4], Free_Cells deck[4], string null, int i, int j, int count_leer, int count, bool check) {
	bool rezult = false;
	bool check1 = false, in_house = false;
	int count_exist = 0;
	int count_leer_ab = 0;
	if (mass[i][j].power == 1 || mass[i][j].power == 2)
		check1 = true;
	int wewe_power = mass[i][j].power - 1;
	if (!check1) {
		for (int a = 0; a < 20; a++) {
			for (int b = 0; b < 8; b++) {
				if (mass[i][j].power - 1 == mass[a][b].power) {
					check = false;
					count_leer_ab = 0;
					count = 0;
					if (mass[a][b].lear != null) { //если карты вообще нет
						while (!check) {
							if (mass[a][b].lear == house_leer[count]) { //если масть карты и масть ячейки дома совпадают
								count_leer_ab = count;
								check = true;
							}
							else count++;
						}
						if (((count_leer == 0 || count_leer == 2) && (count_leer_ab == 1 || count_leer_ab == 3)) || ((count_leer == 1 || count_leer == 3) && (count_leer_ab == 0 || count_leer_ab == 2)))
							count_exist++;
					}
				}
			}
		}
		if (count_exist == 1) {
			if (count_leer == 0 || count_leer == 2) {
				if (((mass[i][j].power - sup_mass[1].power == 1)&& sup_mass[1].lear != null) || ((mass[i][j].power - sup_mass[3].power == 1) && sup_mass[3].lear != null)) {
					count_exist++;
					in_house = true;
				}
			}
			if (count_leer == 1 || count_leer == 3 && !in_house) {
				if (((mass[i][j].power - sup_mass[0].power == 1) && sup_mass[0].lear != null) || ((mass[i][j].power - sup_mass[2].power == 1) && sup_mass[2].lear != null)) {
					count_exist++;
					in_house = true;
				}
			}
		}
		if (count_exist == 1 && !in_house) {
			for (int l = 0; l < 4; l++) {
				if (deck[l].lear != null) {
					if (mass[i][j].power - deck[l].power == 1) {
						check = false;
						count_leer_ab = 0;
						count = 0; //если карты вообще нет
						while (!check) {
							if (deck[l].lear == house_leer[count]) { //если масть карты и масть ячейки дома совпадают
								count_leer_ab = count;
								check = true;
							}
							else count++;
						}
						if (((count_leer == 0 || count_leer == 2) && (count_leer_ab == 1 || count_leer_ab == 3)) || ((count_leer == 1 || count_leer == 3) && (count_leer_ab == 0 || count_leer_ab == 2)))
							count_exist++;
					}
				}
			}
		}
		if (count_exist == 2) return rezult = false;
		if (check1) return rezult = true;
		else return rezult = true;
	}
}
bool cheak_all_deck(Main_Pattern mass[20][8], Free_Cells deck[4], string null, int i, int j, int checkmate, int count, bool check) {
	bool rezult = false;
	bool check1 = false;
	int count_exist = 0;
	for (int a = 0; a < 20; a++) {
		for (int b = 0; b < 8; b++) {
			if (deck[i].power - mass[a][b].power == 1) {
				count_exist++;
				if (mass[a][b].lear != deck[i].lear) {
					check = false;
					int count_leer_ab = 0;
					count = 0;
					if (mass[a][b].lear != null) { //если карты вообще нет
						while (!check) {
							if (mass[a][b].lear == house_leer[count]) { //если масть карты и масть ячейки дома совпадают
								count_leer_ab = count;
								check = true;
							}
							else count++;
						}
					}
					if (((checkmate == 1 || checkmate == 3) && (count_leer_ab == 1 || count_leer_ab == 3)) || ((checkmate == 0 || checkmate == 2) && (count_leer_ab == 0 || count_leer_ab == 2)))
						check1 = true;
				}
			}
		}
	}
	if (check1 || count_exist == 0) return rezult = true;
	else return rezult = false;
}
bool search(bool is_exist_deck, bool is_exist, bool not_allowed, bool replace_card_into_house, bool check, int count_leer, int count, string house_leer[4], Main_Pattern mass[20][8], string null, House sup_mass[4], Free_Cells deck[4]) {
	replace_card_into_house = false;
	int checkmate;
	count_empty_card = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 8; j++) {
			if (i != 19 && mass[i + 1][j].power == 0) { //если не последний ряд и если карты сверху нет
				check = false;
				count_leer = 0;
				count = 0;
				if (mass[i][j].lear != null) { //если карты вообще нет
					while (!check) {
						if (mass[i][j].lear == house_leer[count]) { //если масть карты и масть ячейки дома совпадают
							count_leer = count;
							check = true;
						}
						else count++;
					}
				}
				else count_empty_card++;

				if (not_allowed) {
					for (int i = 0; i < 4; i++) {
						check = false;
						checkmate = 0;
						count = 0;
						if (deck[i].lear != null) { //если карты вообще нет
							while (!check) {
								if (deck[i].lear == house_leer[count]) { //если масть карты в деке и масть ячейки дома совпадают
									checkmate = count;
									check = true;
								}
								else count++;
							}
						}
						is_exist_deck = cheak_all_deck(mass, deck, null, i, j, checkmate, count, check);
						if (is_exist_deck) {
							if (deck[i].power - sup_mass[checkmate].power == 1 && deck[i].lear == house_leer[checkmate]) { //если текущая карта на порядок старше, чем домашняя и если их масти совпадают
								if (deck[i].power == 1 || deck[i].power == 2) { //если это туз или двойка потому что у них другая механика
									sup_mass[checkmate] = House(deck[i].power, deck[i].lear); //перетаскиваем карту
									deck[i] = Free_Cells(0, null); //затираем клетку
									replace_card_into_house = true; //флаг переноски
								}
								else {
									if (count_leer != 0 && count_leer != 2) { //если масть темная
																			  //if (deck[i].power <= sup_mass[i].power && deck[i].power <= sup_mass[2].power) { //если текущая карта меньше значением, чем домашние обратной масти
										if (sup_mass[count_leer].power <= deck[i].power) {
											if (deck[i].power - sup_mass[count_leer].power == 1) {
												sup_mass[count_leer] = House(deck[i].power, deck[i].lear);
												deck[i] = Free_Cells(0, null);
												replace_card_into_house = true;
											}
										}
									}
									if (count_leer != 1 && count_leer != 3) { //если масть светлая
										if (sup_mass[count_leer].power <= deck[i].power) {
											if (deck[i].power - sup_mass[count_leer].power == 1) {
												sup_mass[count_leer] = House(deck[i].power, deck[i].lear);
												deck[i] = Free_Cells(0, null);
												replace_card_into_house = true;
											}
										}
									}
								}
							}
							not_allowed = false;
						}
					}
				}

				is_exist = cheak_all_place(mass, sup_mass, deck, null, i, j, count_leer, count, check);
				if (is_exist) {
					if (mass[i][j].power - sup_mass[count_leer].power == 1 && mass[i][j].lear == house_leer[count_leer]) { //если текущая карта на порядок старше, чем домашняя и если их масти совпадают
						if (mass[i][j].power == 1 || mass[i][j].power == 2) { //если это туз или двойка потому что у них другая механика
							sup_mass[count_leer] = House(mass[i][j].power, mass[i][j].lear); //перетаскиваем карту
							mass[i][j] = Main_Pattern(0, null); //затираем клетку
							replace_card_into_house = true; //флаг переноски
						}
						else {
							if (count_leer != 0 && count_leer != 2) { //если масть темная
								if (sup_mass[count_leer].power <= mass[i][j].power) { //если текущая карта меньше значением, чем домашние обратной масти
									if (mass[i][j].power - sup_mass[count_leer].power == 1) {
										sup_mass[count_leer] = House(mass[i][j].power, mass[i][j].lear);
										mass[i][j] = Main_Pattern(0, null);
										replace_card_into_house = true;
									}
								}
							}
							if (count_leer != 1 && count_leer != 3) { //если масть светлая
								if (sup_mass[count_leer].power <= mass[i][j].power) {
									if (mass[i][j].power - sup_mass[count_leer].power == 1) {
										sup_mass[count_leer] = House(mass[i][j].power, mass[i][j].lear);
										mass[i][j] = Main_Pattern(0, null);
										replace_card_into_house = true;
									}
								}
							}
						}
					}
					else;
					if (i == 19) { //если ряд последний
						count_leer = 0;
						count = 0;
						check = false;
						if (mass[i][j].lear != null) {
							while (!check) {
								if (mass[i][j].lear == house_leer[count]) {
									count_leer = count;
									check = true;
								}
								else count++;
							}
						}
						if (mass[i][j].power - sup_mass[count_leer].power == 1 && mass[i][j].lear == house_leer[count_leer]) {
							if (mass[i][j].power == 1 || mass[i][j].power == 2) {
								sup_mass[count_leer] = House(mass[i][j].power, mass[i][j].lear);
								mass[i][j] = Main_Pattern(0, null);
								replace_card_into_house = true;
							}
							else {
								if (count_leer != 0 && count_leer != 2) {
									if (sup_mass[count_leer].power <= mass[i][j].power) {
										sup_mass[count_leer] = House(mass[i][j].power, mass[i][j].lear);
										mass[i][j] = Main_Pattern(0, null);
										replace_card_into_house = true;
									}
								}
								if (count_leer != 1 && count_leer != 3) {
									if (sup_mass[count_leer].power <= mass[i][j].power) {
										sup_mass[count_leer] = House(mass[i][j].power, mass[i][j].lear);
										mass[i][j] = Main_Pattern(0, null);
										replace_card_into_house = true;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	/*перетаскиваем карты из деки*/
	return replace_card_into_house;
}
void draw(Free_Cells deck[4], House sup_mass[4], string lear_output[4], Main_Pattern mass[20][8], int count_empty_card) {
	clrscr();
	if (count_empty_card == 152) {
		for (int i = 0; i < 4; i++) {
			if (deck[i].power == 0) {
				std::cout << "|     | "; //если клетка пустая
			}//отрисовка деки
		}
		for (int i = 0; i < 4; i++) { //отрисовка дома
			if (sup_mass[i].power == 0) {
				std::cout << "|     | "; //если клетка пустая
			}
			else {
				if (sup_mass[i].power == 1) { //замена 1,11,12,13 на А, J, Q, K
					std::cout << "|  " << lear_output[0] << sup_mass[i].lear << "| ";
				}
				if (sup_mass[i].power == 11) {
					std::cout << "|  " << lear_output[1] << sup_mass[i].lear << "| ";
				}
				if (sup_mass[i].power == 12) {
					std::cout << "|  " << lear_output[2] << sup_mass[i].lear << "| ";
				}
				if (sup_mass[i].power == 13) {
					std::cout << "|  " << lear_output[3] << sup_mass[i].lear << "| ";
				}
				if (sup_mass[i].power != 1 && sup_mass[i].power != 11 && sup_mass[i].power != 12 && sup_mass[i].power != 13) {
					if (sup_mass[i].power != 10)
						std::cout << "|  " << sup_mass[i].power << sup_mass[i].lear;
					if (sup_mass[i].power == 10)
						std::cout << "| " << sup_mass[i].power << sup_mass[i].lear;
				}
			}
		}
		std::cout << std::endl;
		for (int i = 0; i < 9; i++)
			std::cout << "_______"; //если клетка пустая
		std::cout << std::endl;

		bool draw_lines = false, draw_inside = false;
		for (int i = 0; i < 20; i++) { //отрисовка поля
			for (int j = 0; j < 8; j++) {
				draw_lines = false;
				if (i == 6 && (j == 2 || j == 3 || j == 4 || j == 5)) {
					std::cout << "________";
					draw_lines = true;
				}
				if ((i >= 9 && i <= 12 && i!=8 && i!=10 && i != 12) && (j == 3 || j == 4 || j == 5)) {
					std::cout << "        ";
					draw_lines = true;
				}
				if ((i == 7 || i == 8 || i == 9 || i == 9 || i == 10 || i == 11) && j == 2) {
					std::cout << "|       ";
					draw_lines = true;
				}
				if ((i == 8) && (j == 3 || j == 4 || j == 5)) {
					if (j == 3) {
						std::cout << "CONGRATU";
					}
					if (j == 4) {
						std::cout << "LATIONS!";
					}
					if (j == 5) {
						std::cout << "        ";
					}
					draw_lines = true;
				}
				if ((i == 10) && (j == 3 || j == 4 || j == 5)) {
					if (j == 3) {
						std::cout << "A WINRAR";
					}
					if (j == 4) {
						std::cout << " IS YOU!";
					}
					if (j == 5) {
						std::cout << "        ";
					}
					draw_lines = true;
				}
				if ((i == 12) && (j==2 || j == 3 || j == 4 || j == 5)) {
					if (j == 2) {
						std::cout << "|   TRY ";
					}
					if (j == 3) {
						std::cout << "TO BEAT ";
					}
					if (j == 4) {
						std::cout << "ANOTHER ";
					}
					if (j == 5) {
						std::cout << "ONE!    ";
					}
					draw_lines = true;
				}
				if ((i == 7) && (j == 3 || j == 4 || j == 5)) {
					std::cout << "        ";
					draw_lines = true;
				}
				if (i == 13 && (j == 2 || j == 3 || j == 4 || j == 5)) {
					std::cout << "________";
					draw_lines = true;
				}
				if(!draw_lines) std::cout << "|     | "; //если клетка пустая
			}
			std::cout << std::endl;
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (deck[i].power == 0) {
				std::cout << "|     | "; //если клетка пустая
			}//отрисовка дома
			else {
				if (deck[i].power == 1) { //замена 1,11,12,13 на А, J, Q, K
					std::cout << "|  " << lear_output[0] << deck[i].lear << "| ";
				}
				if (deck[i].power == 11) {
					std::cout << "|  " << lear_output[1] << deck[i].lear << "| ";
				}
				if (deck[i].power == 12) {
					std::cout << "|  " << lear_output[2] << deck[i].lear << "| ";
				}
				if (deck[i].power == 13) {
					std::cout << "|  " << lear_output[3] << deck[i].lear << "| ";
				}
				if (deck[i].power != 1 && deck[i].power != 11 && deck[i].power != 12 && deck[i].power != 13) {
					if (deck[i].power != 10)
						std::cout << "|  " << deck[i].power << deck[i].lear << "| ";;
					if (deck[i].power == 10)
						std::cout << "| " << deck[i].power << deck[i].lear << "| ";;
				}
			}
		}
		//std::cout << "\t\t";
		for (int i = 0; i < 4; i++) { //отрисовка дома
			if (sup_mass[i].power == 0) {
				std::cout << "|     | "; //если клетка пустая
			}
			else {
				if (sup_mass[i].power == 1) { //замена 1,11,12,13 на А, J, Q, K
					std::cout << "|  " << lear_output[0] << sup_mass[i].lear << "| ";
				}
				if (sup_mass[i].power == 11) {
					std::cout << "|  " << lear_output[1] << sup_mass[i].lear << "| ";
				}
				if (sup_mass[i].power == 12) {
					std::cout << "|  " << lear_output[2] << sup_mass[i].lear << "| ";
				}
				if (sup_mass[i].power == 13) {
					std::cout << "|  " << lear_output[3] << sup_mass[i].lear << "| ";
				}
				if (sup_mass[i].power != 1 && sup_mass[i].power != 11 && sup_mass[i].power != 12 && sup_mass[i].power != 13) {
					if (sup_mass[i].power != 10)
						std::cout << "|  " << sup_mass[i].power << sup_mass[i].lear << "| ";;;
					if (sup_mass[i].power == 10)
						std::cout << "| " << sup_mass[i].power << sup_mass[i].lear << "| ";;;
				}
			}
		}
		std::cout << std::endl;
		for (int i = 0; i < 9; i++)
			std::cout << "_______"; //если клетка пустая
		std::cout << std::endl;
		for (int i = 0; i < 20; i++) { //отрисовка поля
			for (int j = 0; j < 8; j++) {
				if (mass[i][j].power == 0) {
					std::cout << "|     | "; //если клетка пустая
				}
				else {
					if (mass[i][j].power == 1) {
						std::cout << "|  " << lear_output[0] << mass[i][j].lear << "| ";
					}
					if (mass[i][j].power == 11) {
						std::cout << "|  " << lear_output[1] << mass[i][j].lear << "| ";
					}
					if (mass[i][j].power == 12) {
						std::cout << "|  " << lear_output[2] << mass[i][j].lear << "| ";
					}
					if (mass[i][j].power == 13) {
						std::cout << "|  " << lear_output[3] << mass[i][j].lear << "| ";
					}
					if (mass[i][j].power != 1 && mass[i][j].power != 11 && mass[i][j].power != 12 && mass[i][j].power != 13) {
						if (mass[i][j].power != 10)
							std::cout << "|  " << mass[i][j].power << mass[i][j].lear << "| ";
						if (mass[i][j].power == 10)
							std::cout << "| " << mass[i][j].power << mass[i][j].lear << "| ";
					}
				}
			}
			std::cout << std::endl;
		}
	}
}
int find_freecells(Free_Cells deck[4]) { //поиск свободных ячеек
	int count_cells = 3; //кол-во всех доступных ячеек
	int count_freecells = 0; //кол-во свободных ячеек
	while (count_cells >= 0) { //пока не пройдем по всем ячейкам
		if (deck[count_cells].power == 0) { //если ячейка пуста
			count_freecells++;
			count_cells--;
		}
		else count_cells--;
	}
	return count_freecells;
}
void replace_in_deck(Free_Cells deck[4], Main_Pattern mass[20][8], int i, int j, string null) {
	bool replace_card_in_desk = false; //флаг переноса карты
	if (int check = find_freecells(deck) != 0) { //если кол-во свободных ячеек не 0, то
		while (!replace_card_in_desk) { //если еще не перетащили
			int count = 0;
			if (deck[count].power == 0 && count < 4) { //если место свободно
				deck[count] = Free_Cells(mass[i][j].power, mass[i][j].lear); //переносим карту
				mass[i][j] = Main_Pattern(0, null); //затираем ячейку
				replace_card_in_desk = true; //выдаем флаг
			}
			else count++;
			if (count == 4 && !replace_card_in_desk) {
				replace_card_in_desk = true; //если все ячейки заняты, то выдаем флаг принудительно и завершаем
				std::cout << "Нет свободных ячеек для перемещения карты." << std::endl;
			}
		}
	}
}
bool findcard(A_card A[2], Main_Pattern mass[20][8], bool if_column, bool find_current_deck, bool replace_current_deck, bool replace_current_house, bool deck_colunm) {
	bool A_find = false, B_find = false, rezult = false;
	if (deck_colunm) {
		for (int i = 0; i < 4; i++) { //отрисовка поля
			if (A[0].power == deck[i].power&&A[0].lear == deck[i].lear) {
				A[0].x = i;
				A_find = true;
			}
		}
		if (!A_find) return rezult == false;
		else return rezult = true;
	}
	if (replace_current_house) {
		for (int i = 0; i < 20; i++) { //отрисовка поля
			for (int j = 0; j < 8; j++) {
				if (A[0].power == mass[i][j].power&&A[0].lear == mass[i][j].lear) {
					A[0].x = i;
					A[0].y = j;
					A_find = true;
				}
			}
		}
		if (!A_find) return rezult == false;
		else return rezult = true;
	}
	if (replace_current_deck) {
		for (int i = 0; i < 4; i++) { //отрисовка поля
			if (A[0].power == deck[i].power&&A[0].lear == deck[i].lear) {
				A[0].x = i;
				A_find = true;
			}
		}
		for (int i = 0; i < 20; i++) { //отрисовка поля
			for (int j = 0; j < 8; j++) {
				if (A[1].power == mass[i][j].power&&A[1].lear == mass[i][j].lear) {
					A[1].x = i;
					A[1].y = j;
					B_find = true;
				}
			}
		}
		if (!A_find || !B_find) return rezult = false;
		if (A_find && B_find) return rezult = true;
	}
	if (find_current_deck) {
		for (int i = 0; i < 4; i++) { //отрисовка поля
			if (A[0].power == deck[i].power&&A[0].lear == deck[i].lear) {
				A[0].x = i;
				A_find = true;
			}
		}
		if (!A_find) return rezult = false;
		else return rezult = true;
	}
	if (if_column) {
		for (int i = 0; i < 20; i++) { //отрисовка поля
			for (int j = 0; j < 8; j++) {
				if (A[0].power == mass[i][j].power&&A[0].lear == mass[i][j].lear) {
					A[0].x = i;
					A[0].y = j;
					A_find = true;
				}
			}
		}
		if (!A_find) return rezult = false;
		else return rezult = true;
	}
	else {
		for (int i = 0; i < 20; i++) { //отрисовка поля
			for (int j = 0; j < 8; j++) {
				if (A[0].power == mass[i][j].power&&A[0].lear == mass[i][j].lear) {
					A[0].x = i;
					A[0].y = j;
					A_find = true;
				}
				if (A[1].power == mass[i][j].power&&A[1].lear == mass[i][j].lear) {
					A[1].x = i;
					A[1].y = j;
					B_find = true;
				}
			}
		}
		if (!A_find || !B_find) return rezult = false;
		if (A_find && B_find) return rezult = true;
	}
}
bool check_current_lear(A_card A[2], Main_Pattern mass[20][8], string house_leer[4]) {
	bool rezult = false;
	int A0_lear, A1_lear;
	for (int i = 0; i < 4; i++) {
		if (mass[A[0].x][A[0].y].lear == house_leer[i]) {//ищем масть первой карты
			A0_lear = i;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (mass[A[1].x][A[1].y].lear == house_leer[i]) {//ищем масть второй карты
			A1_lear = i;
		}
	}
	if (A0_lear == A1_lear) {//если масть одна и та же
		std::cout << "Нельзя переместить карту на одну и ту же масть." << std::endl;
		return rezult = false;
	}
	else {
		if ((abs(A0_lear - A1_lear)) != 0 || abs(A0_lear - A1_lear) == 1) {//если масти четная+нечетная, то работаем
			if ((mass[A[1].x][A[1].y].power - mass[A[0].x][A[0].y].power) == 1) {
				return rezult = true;
			}
			else {
				std::cout << "Нельзя переместить карту на данную." << std::endl;
				return rezult = false;
			}
		}
		else {
			std::cout << "Нельзя переместить карту на данную." << std::endl;
			return rezult = false;
		}
	}
}
bool check_current_lear_deck(A_card A[2], Main_Pattern mass[20][8], string house_leer[4], Free_Cells deck[4]) {
	bool rezult = false;
	int A0_lear, A1_lear;
	for (int i = 0; i < 4; i++) {
		if (deck[A[0].x].lear == house_leer[i]) {//ищем масть первой карты
			A0_lear = i;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (mass[A[1].x][A[1].y].lear == house_leer[i]) {//ищем масть второй карты
			A1_lear = i;
		}
	}
	if (A0_lear == A1_lear) {//если масть одна и та же
		std::cout << "Нельзя переместить карту на одну и ту же масть." << std::endl;
		return rezult = false;
	}
	else {
		if ((abs(A0_lear - A1_lear)) != 0 || abs(A0_lear - A1_lear) == 1) {//если масти четная+нечетная, то работаем
			if (( mass[A[1].x][A[1].y].power - deck[A[0].x].power) == 1) {
				return rezult = true;
			}
			else {
				std::cout << "Нельзя переместить карту на данную." << std::endl;
				return rezult = false;
			}
		}
		else {
			std::cout << "Нельзя переместить карту на данную." << std::endl;
			return rezult = false;
		}
	}
}
bool check_lear(A_card A[2], Main_Pattern mass[20][8], Free_Cells deck[4], Free_column free_column[5], string house_leer[4], string null, bool deck_colunm, bool if_column, int column, int count_free_column, bool find_current_deck) {
	bool rezult = false;
	bool check_cl;
	bool check_cl2;
	if (find_current_deck) {
		check_cl = check_free_deck(A, mass, house_leer, null, A[0].x, A[1].x, A[1].y);
		if (check_cl && mass[A[1].x + 1][A[1].y].power == 0) {
			return rezult;
		}
	}
	if (if_column) {
		check_cl = check_column(mass, house_leer, null, A[0].x, A[0].y);
		int fr_clls = find_freecells(deck);
		int hw_crd = how_card(A, mass);
		if (fr_clls*(2 ^ (count_free_column)+count_free_column * 2 >= hw_crd)) {
			if (check_cl && mass[0][column].power == 0) {
				return rezult;
			}
		}
	}
	if (deck_colunm) {
		return rezult;
	}
	else {
		check_cl = check_column(mass, house_leer, null, A[0].x, A[0].y);
		check_cl2 = check_current_lear(A, mass, house_leer);
		int fr_clls = find_freecells(deck);
		int hw_crd = how_card(A, mass);
		if ((fr_clls*(2 ^ (count_free_column)+count_free_column * 2)+1 >= hw_crd)) {
			if (check_cl && check_cl2) {
				if (mass[A[1].x + 1][A[1].y].power == 0) { //если под картой есть еще одна
					if ((mass[A[1].x][A[1].y].power - mass[A[0].x][A[0].y].power) == 1) { //если карты идут в правильном порядке
						return rezult;
					}
					else std::cout << "Нельзя переместить карту на данную." << std::endl;
				}
			}
			else std::cout << "Нельзя переместить карту на данную." << std::endl;
		}
		else {
			rezult = true;
			return rezult;
		}
	}
}
void replace_card(A_card A[2], Main_Pattern mass[20][8], bool if_column, int column) {
	bool check = false;
	int count_deck = 0;
	if (if_column) {
		int a = 0;
		int i = A[0].x;
		int j = A[0].y;
		while (i < 20) {
			mass[a][column] = Main_Pattern(mass[i][A[0].y].power, mass[i][A[0].y].lear); //переносим карту
			mass[i][A[0].y] = Main_Pattern(0, null); //затираем ячейку
			i++;
			a++;
		}
	}
	else {
		int i = A[0].x;
		int x = A[1].x;
		while (i < 20 && x < 19) {
			mass[x + 1][A[1].y] = Main_Pattern(mass[i][A[0].y].power, mass[i][A[0].y].lear); //переносим карту
			mass[i][A[0].y] = Main_Pattern(0, null); //затираем ячейку
			if (mass[i + 1][A[0].y].power == 0 && mass[i + 1][A[0].y].lear == "0")
				break;
			i++;
			x++;
		}
	}
}
void replace_in_deck(A_card A[2], Free_Cells deck[4], Main_Pattern mass[20][8], string null) {
	bool check = false;
	int i = 0;
	while (!check) {	
		if (deck[i].power == 0) {
			deck[i] = Free_Cells(mass[A[0].x][A[0].y].power, mass[A[0].x][A[0].y].lear);
			mass[A[0].x][A[0].y] = Main_Pattern(0, null);
			check = true;
		}
		i++;
	}
}
void replace_from_deck(A_card A[2], Free_Cells deck[4], Main_Pattern mass[20][8], string null) {
	mass[A[1].x + 1][A[1].y] = Main_Pattern(deck[A[0].x].power, deck[A[0].x].lear);
	deck[A[0].x] = Free_Cells(0, null);
}
bool check_deck(A_card A[2], Main_Pattern mass[20][8]) {
	bool rezult = false;
	if (mass[A[0].x + 1][A[0].y].power == 0)
		return rezult = true;
	else
		return rezult;
}
bool check_deck_replace(A_card A[2], Main_Pattern mass[20][8], string house_leer[4], Free_Cells deck[4]) {
	bool rezult = false;
	bool check_place = false;
	check_place = check_current_lear_deck(A, mass, house_leer, deck);
	if (check_place) {
		if (mass[A[1].x + 1][A[1].y].power == 0)
			return rezult = true;
		else
			return rezult;
	}
}
bool check_house(A_card A[2], Main_Pattern mass[20][8], House sup_mass[4], string house_leer[4]) {
	bool check = false, rezult = false, miss = false;
	int i = 0;
	while (!check) {
		if (mass[A[0].x + 1][A[0].y].power == 0) //если карты выбранной ниже нет
			if (A[0].lear == house_leer[i]) //и если масти дома совпадают
				if (A[0].power - sup_mass[i].power == 1) { //и если соблюдается порядок карт по старшинству
				check = true;
				A[1].x = i;
			}
				else
					i++;
			else
				i++;
		else
			i++;
		if (i == 4 && !check) {
			miss = true;
			check = true;
		}
	}
	if (check && !miss) return rezult = true;
	else return rezult;
}
void replace_in_house(A_card A[2], House sup_mass[4], Main_Pattern mass[20][8], string null) {
	sup_mass[A[1].x] = House(mass[A[0].x][A[0].y].power, mass[A[0].x][A[0].y].lear);
	mass[A[0].x][A[0].y] = Main_Pattern(0, null);
}
void replace_card_from_deck_in_column(A_card A[2], Main_Pattern mass[20][8], Free_Cells deck[4], int column, string null) {
	mass[0][column] = Main_Pattern(deck[A[0].x].power, deck[A[0].x].lear);
	deck[A[0].x] = Free_Cells(0, null);
}
bool check_entry_file(Card_Deck CD[36], string null, string house_leer[4]) {
	/*ПРОВЕРКА НА ЕБАНАТА
	просмотрим на входе перед обработкой всех данных
	необходима проверка на соответствие всем заданным картам: 
	1) не должно быть лишних карт
	2) никаких бля лишних мастей, очепяток и тд
	3) должно быть только по 4 масти с каждой карты начиная с 6 до туза*/

	int temp_column, 
		temp_line,
		temp_power;
	string temp_lear;

	const int C_MASS = 9;
	int START_POWER = 6;
	const int LAST_POWER = 13;

	int count = 0;

	for (int i = 0; i < C_MASS && count >= 0 && count < 52; i++) {
		for (int j = 0; j < 4; j++) {
			CD[count].power = START_POWER;
			CD[count].lear = house_leer[j];
			count++;
		}
		START_POWER++;
		if (START_POWER > LAST_POWER) {
			for (int j = 0; j < 4; j++) {
				CD[count].power = 1;
				CD[count].lear = house_leer[j];
				count++;
			}
		}
	}

	for (int i = 0; i < 52; i++) {
		cout << CD[i].power << " " << CD[i].lear;
		if (CD[i].is_Find_Already) cout << " true" << endl;
		else cout << " false" << endl;
	}
	clrscr();
	std::ifstream in("game.txt"); // открываем файл для чтения

	count = 0;

	bool isValueCheckedDone = false;
	if (in.is_open()) {
		for (int j = 0; in >> temp_line >> temp_column >> temp_power >> temp_lear; j++)
		{
			isValueCheckedDone = false;
			if (j < 52) {
				for (int i = 0; i < 52; i++) {
					if (CD[i].power == temp_power && CD[i].lear == temp_lear) {
						if (CD[i].is_Find_Already) {
							cout << "card " << temp_power << temp_lear << "[" << temp_line << ", " << temp_column << "] is already exist in line [" << CD[i].x << ", " << CD[i].y << "]\ncheck the txt file" << endl;
							return false;
						}
						else {
							CD[i].is_Find_Already = true;
							CD[i].x = temp_line;
							CD[i].y = temp_column;
							isValueCheckedDone = true;
						}
					}
				}

				if (!isValueCheckedDone) {
					bool isPowerRight = false,
						isLearRight = false;

					for (int i = 0; i <= LAST_POWER; i++) {
						if (temp_power == i) {
							isPowerRight = true;
							break;
						}
						else;
					}
					if (!isPowerRight) {
						cout << "power " << temp_power << " in card " << temp_power << " " << temp_lear << "[" << temp_line << ", " << temp_column << "] doesn't exist\ncheck txt file" << endl;
						return false;
					}
					else {
						for (int i = 0; i < 4; i++) {
							if (temp_lear == house_leer[i]) {
								isLearRight = true;
								break;
							}
							else;
						}
					}
					if (!isValueCheckedDone && !isPowerRight && !isLearRight) {
						cout << "unexpected error" << endl;
						return false;
					}
					if (!isValueCheckedDone && isPowerRight && !isLearRight) {
						cout << "lear " << temp_lear << " in card " << temp_power << " " << temp_lear << "[" << temp_line << ", " << temp_column << "] doesn't exist\ncheck txt file" << endl;
						return false;
					}
				}
			}
			else {
				if (temp_power != 0 || temp_lear != "0") {
					cout << "card " << temp_power << " " << temp_lear << "[" << temp_line << ", " << temp_column << "] can't be created\ncheck txt file"<< endl;
					return false;
				}
			}
		}
	}
}
void undo_action(vector<Log_Cards> log_file, Main_Pattern mass[20][8], string null) {
	int MASS = log_file.size() - 1;
	mass[log_file[MASS].old_axis_x][log_file[MASS].old_axis_y] = Main_Pattern(log_file[MASS].power, log_file[MASS].lear);
	mass[log_file[MASS].new_axis_x][log_file[MASS].new_axis_y] = Main_Pattern(0, null);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	bool first_run = true;
	bool autoreplace = false;
	bool check_repeat = true;
	std::string choose_autoreplace;
	std::string choose_replace_from_deck_in_column;
	std::string options[4] = { "y","Y","yes","YES" };
	while (1) {
		std::ifstream in("game.txt"); // открываем файл для чтения
		if (in.is_open())
		{
			Main_Check = check_entry_file(CD, null, house_leer);
			if (Main_Check) {
				while (in >> line >> column >> power >> lear)
				{
					new_pattern.push_back(Pattern(line, column, power, lear)); //создание первичной записи о раскладе
				}
			}
		}
		in.close();
		if (Main_Check) {
			int count = 0;
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 8; j++) {
					mass[i][j] = Main_Pattern(new_pattern[count].power, new_pattern[count].lear); //создание основного массива на основе первичной записи
					count++;
				}
			}
			for (int i = 0; i < 4; i++) { //заполнение "дома" нулями
				sup_mass[i] = House(0, null);
				deck[i] = Free_Cells(0, null);
			}
			if (first_run) {
				draw(deck, sup_mass, lear_output, mass, count_empty_card);
				std::cout << "Включить автоперемещение свободных карт в дом? \ny/n" << std::endl;
				std::cin >> choose_autoreplace;
				if (choose_autoreplace == options[0] || choose_autoreplace == options[1] || choose_autoreplace == options[2] || choose_autoreplace == options[3]) {
					autoreplace = true; //флаг автоперекидывания
					first_run = false; //-флаг первого запуска
				}
				else;
			}
			int main_choose = 0;
			while (main_choose != 7) {
				if (autoreplace) { //если можно то выбрасываем карты
					while (replace_card_into_house) {
						replace_card_into_house = search(is_exist_deck, is_exist, not_allowed, replace_card_into_house, check, count_leer, count, house_leer, mass, null, sup_mass, deck);
					}
				}
				draw(deck, sup_mass, lear_output, mass, count_empty_card);
				if (count_empty_card != 152) {
					std::cout << "Choose your destiny: \n1. Переместить карту\n2. undo \n3. О программе\n4. Выход из программы" << std::endl;
					std::cin >> main_choose;
					bool main_choose_already = false;
					if (main_choose == 1) {
						std::cout << "\t1. в столбец\n\t2. на карту\n\t3. в ячейки\n\t4. из ячейки\n\t5. в дом" << std::endl;
						std::cin >> main_choose;
						main_choose_already = true;
					}
					if (!main_choose_already) { //если не выбирали перенос, то сдвигаем
						if (main_choose == 2) main_choose = 8;
						else if (main_choose == 3) main_choose = 6;
						else if (main_choose == 4) main_choose = 7;
					}
					bool check, check_l, check_cl, 
						if_column = false, //если будем переносить карту (стопку карт) в столбец
						find_current_deck = false, 
						replace_current_deck = false, 
						replace_current_house = false, 
						deck_colunm = false;
					int choose_column, 
						find_dk;
					std::string choose_cl;
					switch (main_choose) {
					case 1: {
						if_column = true;
						std::cout << "Выберите карту, которую нужно перенести." << std::endl;
						std::cin >> A[0].power >> A[0].lear;
						x = 0;
						if (card_is_exist(mass, A, house_leer, x)) {
							count_free_column = 0;
							check_cl = find_column(mass, count_free_column, free_column);
							if (check_cl) {
								for (int i = 0; i < 5; i++) {
									if (free_column[i].count != NULL)
										count_free_column++;
								}
								if (count_free_column == 1)
									std::cout << "Доступен свободный столбец";
								else
									std::cout << "Доступны свободные столбцы";
								bool first_count = true;
								while (count_free_column > 0) {
									if (first_count) {
										std::cout << " " << free_column[count_free_column - 1].count + 1;
										first_count = false;
										if (count_free_column == 1)
											std::cout << " ";
										else
											std::cout << ", ";
										first_count = false;
									}
									else {
										std::cout << free_column[count_free_column - 1].count + 1;
										if (count_free_column == 1)
											std::cout << " ";
										else
											std::cout << ", ";
									}
									count_free_column--;
								}
								std::cout << "для переноса. Выберете доступный столбец." << std::endl;
								std::cin >> choose_column;
								choose_column = choose_column - 1;
								check = findcard(A, mass, if_column, find_current_deck, replace_current_deck, replace_current_house, deck_colunm);
								check_l = check_lear(A, mass, deck, free_column, house_leer, null, deck_colunm, if_column, choose_column, count_free_column, find_current_deck);
								if (check) { //если карты вообще есть на поле
									if (!check_l) { //если их можно перетащить
										replace_card(A, mass, if_column, choose_column);
										replace_card_into_house = true;
										if (autoreplace) { //если можно то выбрасываем карты
											while (replace_card_into_house) {
												replace_card_into_house = search(is_exist_deck, is_exist, not_allowed, replace_card_into_house, check, count_leer, count, house_leer, mass, null, sup_mass, deck);
											}
										}

									}
								}
								else {
									std::cout << "Нельзя переместить выбранную карту." << std::endl;
									getch();
								}
							}
							for (int i = 0; i < 5; i++) {
								if (free_column[i].count != NULL)
									free_column[i].count = 0;
							}
						}
						else {
							std::cout << "Некорректный ввод. Повторите попытку." << std::endl;
							getch();
						}
						break;
					}
					case 2: {
						std::cout << "Выберите карту, которую нужно перенести." << std::endl;
						std::cin >> A[0].power >> A[0].lear;
						x = 0;
						if (card_is_exist(mass, A, house_leer, x)) {
							std::cout << "Выберите карту, на которую нужно перенести." << std::endl;
							std::cin >> A[1].power >> A[1].lear;
							x = 1;
							if (card_is_exist(mass, A, house_leer, x)) {
								check = findcard(A, mass, if_column, find_current_deck, replace_current_deck, replace_current_house, deck_colunm);
								check_l = check_lear(A, mass, deck, free_column, house_leer, null, deck_colunm, if_column, choose_column, count_free_column, find_current_deck);
								if (check) { //если карты вообще есть на поле
									if (!check_l) { //если их можно перетащить
										log_file.push_back({ mass[A[0].x][A[0].y].power, mass[A[0].x][A[0].y].lear, A[0].x, A[0].y, A[1].x + 1, A[1].y });
										replace_card(A, mass, if_column, choose_column);
										replace_card_into_house = true;
										if (autoreplace) { //если можно то выбрасываем карты
											while (replace_card_into_house) {
												replace_card_into_house = search(is_exist_deck, is_exist, not_allowed, replace_card_into_house, check, count_leer, count, house_leer, mass, null, sup_mass, deck);
											}
										}

									}
								}
								else {
									std::cout << "Нельзя переместить выбранную карту." << std::endl;
									getch();
								}
							}
							else {
								std::cout << "Некорректный ввод. Повторите попытку." << std::endl;
								getch();
							}
						}
						else {
							std::cout << "Некорректный ввод. Повторите попытку." << std::endl;
							getch();
						}
						break;
					}
					case 3: {
						if_column = true;
						find_dk = find_freecells(deck);
						if (find_dk != 0) {
							std::cout << "Выберите карту, которую нужно перенести." << std::endl;
							std::cin >> A[0].power >> A[0].lear;
							x = 0;
							bool temp = card_is_exist(mass, A, house_leer, x);
							if (temp) {
								check = findcard(A, mass, if_column, find_current_deck, replace_current_deck, replace_current_house, deck_colunm);
								check_l = check_deck(A, mass);
								if (check) { //если карты вообще есть на поле
									if (check_l) { //если их можно перетащить
										replace_in_deck(A, deck, mass, null);
										replace_card_into_house = true;
										if (autoreplace) { //если можно то выбрасываем карты
											while (replace_card_into_house) {
												replace_card_into_house = search(is_exist_deck, is_exist, not_allowed, replace_card_into_house, check, count_leer, count, house_leer, mass, null, sup_mass, deck);
											}
										}
									}
								}
							}
						}
						else {
							std::cout << "Некорректный ввод. Повторите попытку." << std::endl;
							getch();
						}
						break;
					}
					case 4: {
						find_dk = find_freecells(deck);
						if (find_dk != 4) {
							std::cout << "Выберите карту, которую нужно перенести." << std::endl;
							std::cin >> A[0].power >> A[0].lear;
							x = 0;
							if (card_is_exist(mass, A, house_leer, x)) {
								check_cl = find_column(mass, count_free_column, free_column);
								if (check_cl) {
									deck_colunm = true;
									std::cout << "Доступны свободные столбцы. Выбрать? y/n\n";
									std::cin >> choose_replace_from_deck_in_column;
									if (choose_replace_from_deck_in_column == options[0] || choose_replace_from_deck_in_column == options[1] || choose_replace_from_deck_in_column == options[2] || choose_replace_from_deck_in_column == options[3]) {
										std::cout << "Доступны свободные столбцы";
										for (int i = 0; i < 5; i++) {
											if (free_column[i].count != NULL)
												count_free_column++;
										}
										int i = count_free_column;
										bool first_count = true;
										while (i >= 0) {
											if (first_count) {
												std::cout << " " << free_column[i].count + 1;
												first_count = false;
												if (i == 0)
													std::cout << " ";
												else
													std::cout << ", ";
												first_count = false;
											}
											else {
												std::cout << free_column[i].count + 1;
												if (i == 0)
													std::cout << " ";
												else
													std::cout << ", ";
											}
											i--;
										}
										deck_colunm = true;
										std::cout << "для переноса. Выберете доступный столбец." << std::endl;
										std::cin >> choose_column;
										choose_column = choose_column - 1;
										check = findcard(A, mass, if_column, find_current_deck, replace_current_deck, replace_current_house, deck_colunm);
										check_l = check_lear(A, mass, deck, free_column, house_leer, null, deck_colunm, if_column, choose_column, count_free_column, find_current_deck);
										if (check) { //если карты вообще есть на поле
											if (!check_l) { //если их можно перетащить
												replace_card_from_deck_in_column(A, mass, deck, choose_column, null);
												replace_card_into_house = true;
												if (autoreplace) { //если можно то выбрасываем карты
													while (replace_card_into_house) {
														replace_card_into_house = search(is_exist_deck, is_exist, not_allowed, replace_card_into_house, check, count_leer, count, house_leer, mass, null, sup_mass, deck);
													}
												}

											}
										}
									}
									//if (choose_replace_from_deck_in_column == options[1])
									else
										check_cl = false;
								}
								if (!check_cl) {
									deck_colunm = false;
									replace_current_deck = true;
									std::cout << "Выберите карту, на которую нужно перенести." << std::endl;
									std::cin >> A[1].power >> A[1].lear;
									check = findcard(A, mass, if_column, find_current_deck, replace_current_deck, replace_current_house, deck_colunm);
									check_l = check_deck_replace(A, mass, house_leer, deck);
									if (check) {
										if (check_l) {
											replace_from_deck(A, deck, mass, null);
											replace_card_into_house = true;
											if (autoreplace) { //если можно то выбрасываем карты
												while (replace_card_into_house) {
													replace_card_into_house = search(is_exist_deck, is_exist, not_allowed, replace_card_into_house, check, count_leer, count, house_leer, mass, null, sup_mass, deck);
												}
											}
										}
									}
								}
							}
						}
						else {
							std::cout << "Некорректный ввод. Повторите попытку." << std::endl;
							getch();
						}
						break;
					}
					case 5: {
						replace_current_house = true;
						std::cout << "Выберите карту, которую нужно перенести." << std::endl;
						std::cin >> A[0].power >> A[0].lear;
						x = 0;
						if (card_is_exist(mass, A, house_leer, x)) {
							check = findcard(A, mass, if_column, find_current_deck, replace_current_deck, replace_current_house, deck_colunm);
							check_l = check_house(A, mass, sup_mass, house_leer);
							if (check) { //если карты вообще есть на поле
								if (check_l) { //если их можно перетащить
									replace_in_house(A, sup_mass, mass, null);
									replace_card_into_house = true;
									if (autoreplace) { //если можно то выбрасываем карты
										while (replace_card_into_house) {
											replace_card_into_house = search(is_exist_deck, is_exist, not_allowed, replace_card_into_house, check, count_leer, count, house_leer, mass, null, sup_mass, deck);
										}
									}
								}
							}
						}
						else {
							std::cout << "Некорректный ввод. Повторите попытку." << std::endl;
							getch();
						}
						break;
					}
					case 6: {
						clrscr();
						std::cout << "\n\n\n\n\n\t\t\t    Солитер Indev 1.2.2 \n\n\n\t\t\t  Powered by K4TZENFLE1SH \n\n\n\n\n\t\t\t\t2019-2021." << std::endl;
						getch();
						break;
					}
					case 7: {
						return 0;
					}
					case 8: {
						undo_action(log_file, mass, null);
						break;
					}
					default: {
						std::cout << "Введена неверная команда или неверный выбор текущей команды. Повторите запрос." << std::endl;
						getch();
						break;
					}
					}
				}
				else {
					getch();
					return 0;
				}
			}
		}
		else {
			std::string repeat_choose;
			cout << "\n retry? y/n" << endl;
			cin >> repeat_choose;
			if (repeat_choose == options[0] || repeat_choose == options[1] || repeat_choose == options[2] || repeat_choose == options[3]) {
				std::fill(std::begin(CD), std::end(CD), Card_Deck());
			}
			else {
				system("pause");
				return -1;
			}
		}
	}
}