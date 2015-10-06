#ifndef CHESS_UI_
#define CHESS_UI_

#include <SDL.h>
#include <SDL_video.h>
#include "ChessProg.h"

#define WIN_W 800
#define WIN_H 600
#define IMG_W 60
#define IMG_H 74
#define BUTTON_H 50
#define BUTTON_W 100
#define TILE 65
#define SAVE_SLOTS 7 // remove after added to chessprog.h

#define WIN_HEIGHT 600
#define WIN_WIDTH 800

//structures
typedef struct button
{
	char* name;
	SDL_Surface * img;
	int x;
	int y;
	int abs_x;
	int abs_y;
	int width;
	int height;
	void(*handler)(void*); // pointer to the button handler function
	//void* args;
	//char* args;
	int args;
} Button;

typedef struct label
{
	char* name;
	SDL_Surface * img;
	int x;
	int y;
	int width;
	int height;
} Label;

typedef struct panel
{
	char* name;
	SDL_Surface * img;
	int x;
	int y;
	int width;
	int height;
} Panel;

typedef struct window
{
	SDL_Surface * surface;
	char* title;
	int width;
	int height;
} Window;

typedef enum { WINDOW = 0, PANEL = 1, LABEL = 2, BUTTON = 3 } CONTROL;

typedef struct treenode
{
	void* control;
	CONTROL type;
	int child_num;
	struct treenode** children;
	struct treenode* parent;
} TreeNode;


// Globals
extern int glob_quit;
extern TreeNode *mainMenu;
extern TreeNode *settingsMenu;
extern TreeNode *playerSelection;
extern TreeNode *boardSetting;
extern TreeNode *gameWindow;
extern Button **buttons;
extern int buttons_count;

// GUI Framework funcs
TreeNode* new_node(void* control, CONTROL type, int child_num, TreeNode* parent);
TreeNode* new_window(char *title, int width, int height, int children);
TreeNode* new_panel(TreeNode *parent, char* name, int x, int y, int width, int height, int children, char* file);
TreeNode* new_label(TreeNode *parent, char* name, int x, int y, int width, int height, int children, char* file);
TreeNode* new_button(TreeNode *parent, char* name, int x, int y, int width, int height, int children, char* file, void* handler, void* args);
int draw_tree_rec(Window* root, TreeNode* node);
int draw_tree(TreeNode* root);
void free_tree(TreeNode *node);
void get_screen_buttons(TreeNode *node);
int is_click_on_button(int x, int y, Button *button);
void run_events_loop(TreeNode* screen);
void add_label_to_button(TreeNode *button, char* pic);
void remove_label_from_button(TreeNode *button);
//void keybpard_handler(TreeNode *screen, SDLKey key);

#endif CHESS_UI_