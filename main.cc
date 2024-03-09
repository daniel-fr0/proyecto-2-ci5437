// Game of Othello -- Example of main
// Universidad Simon Bolivar, 2012.
// Author: Blai Bonet
// Last Revision: 1/11/16
// Modified by: 

#include <iostream>
#include <limits>
#include "othello_cut.h" // won't work correctly until .h is fixed!
#include "utils.h"
#include <limits>

const int INFINITY = std::numeric_limits<int>::max();
const int NEGATIVE_INFINITY = std::numeric_limits<int>::min();

#include <unordered_map>

using namespace std;

unsigned expanded = 0;
unsigned generated = 0;
int tt_threshold = 32; // threshold to save entries in TT

// Transposition table (it is not necessary to implement TT)
struct stored_info_t {
    int value_;
    int type_;
    enum { EXACT, LOWER, UPPER };
    stored_info_t(int value = -100, int type = LOWER) : value_(value), type_(type) { }
};

struct hash_function_t {
    size_t operator()(const state_t &state) const {
        return state.hash();
    }
};

class hash_table_t : public unordered_map<state_t, stored_info_t, hash_function_t> {
};

hash_table_t TTable[2];

//int maxmin(state_t state, int depth, bool use_tt);
//int minmax(state_t state, int depth, bool use_tt = false);
//int maxmin(state_t state, int depth, bool use_tt = false);
int negamax(state_t state, int depth, int color, bool use_tt = false){
    generated++;
    if (depth==0 || state.terminal()) {
        return color * state.value();
    };
    // Inicializamos el alpha y una variable para saber si esta jugando white o black
    int alpha = NEGATIVE_INFINITY;
    bool actual = color == 1;
    // Childs tendra los nodos hijos del nodo state que estamos revisando
    vector<int> childs = state.movs_posibles(actual);
    // Si el state tiene hijos que falten revisar
    if (!childs.empty()) { 
        for (int posicion : childs) {
            expanded++;
            // Generamos el siguiente estado en el arreglo
            state_t child = state.move(actual,posicion);
            // Se calcula el alpha
            alpha = max(alpha,-negamax(child,depth-1,-color,use_tt=false));
        };
    }
    // Si no tiene movimientos, se pasa el turno, se pasa al siguiente estado (depth-1)
    else {
        alpha = max(alpha,-negamax(state,depth-1,-color,use_tt=false));        
    }
    return alpha;
};

int negamax(state_t state, int depth, int alpha, int beta, int color, bool use_tt = false){
    generated++;  
    if (depth==0 || state.terminal()) {
        return color * state.value();
    };  
    // Inicializamos el alpha y una variable para saber si esta jugando white o black
    int score = NEGATIVE_INFINITY;
    bool actual = color == 1;
    // Childs tendra los nodos hijos del nodo state que estamos revisando
    vector<int> childs = state.movs_posibles(actual);
    // Si el state tiene hijos que falten revisar
    if (!childs.empty()) { 
        for (int posicion : childs) {
            expanded++;     
            // Generamos el siguiente estado en el arreglo
            state_t child = state.move(actual,posicion);
            // Se calcula el alpha
            int val = -negamax(child,depth-1,-beta,-alpha,-color,use_tt=false);
            score = max(score,val);
            alpha = max(alpha,val);
            if (alpha >= beta) {
                break;
            }
        };
    } 
    // Si no tiene, tomamos el score actual 
    else {
        int val = -negamax(state,depth-1,-beta,-alpha,-color,use_tt=false);
        score = max(score,val);
    }
    return score;
};

bool test(state_t state, int depth, int score, int color,string condition){
    if (depth == 0 || state.terminal()) {
        if (condition == ">") {
            return state.value() > score;
        }else{
            return state.value() >= score;
        }
    }
    // Incializamos una variable para saber si esta jugando white o black
    bool actual = color == 1;
    // Childs tendra los nodos hijos del nodo state que estamos revisando
    vector<int> childs = state.movs_posibles(actual);
    // Si el state tiene hijos que falten revisar
    if (!childs.empty()) { 
        for (int posicion : childs) {
            expanded++;
            // Generamos el siguiente estado en el arreglo
            state_t state_movement = state.move(actual,posicion);
            // Hacemos el test del subarbol
            if (actual && test(state_movement,depth-1,-color,score,condition)) {
                return true;
            }
            if (!actual && !test(state_movement,depth-1,-color,score,condition)) {
                return false;
            }            
        };
    }
    
    // Si no tiene, tomamos el resultado del test al estado actual actual 
    else {
        if (actual && test(state,depth-1,-color,score,condition)) {
            return true;
        }
        if (!actual && !test(state,depth-1,-color,score,condition)) {
            return false;
        }
    }
    return !actual;
}

int scout(state_t state, int depth, int color, bool use_tt = false){
    generated++;
    bool first_child = true;
    if (depth == 0 || state.terminal()) {
        return state.value();
    };
    // Incializamos el score
    int score = 0;
    // Incializamos una variable para saber si esta jugando white o black
    bool actual = color == 1; 
    // Childs tendra los nodos hijos del nodo state que estamos revisando
    vector<int> childs = state.movs_posibles(actual);
    // Si el state tiene hijos que falten revisar
    if (!childs.empty()) { 
        for (int posicion : childs) {
            expanded++;
            // Generamos el siguiente estado en el arreglo
            state_t state_movement = state.move(actual,posicion);
            if (first_child) {
                first_child = false;
                score = scout(state_movement,depth-1,-color,use_tt);
            }
            else {
                if (actual && test(state_movement,depth,score,-color,">")) {
                    score = scout(state_movement,depth-1,-color,use_tt);
                }
                if (!actual && !test(state_movement,depth,score,-color,">=")) {
                    score = scout(state_movement,depth-1,-color,use_tt);
                }
            }            
        };
    } 
    // Si no tiene, tomamos el score actual 
    else {
        score = scout(state,depth-1,-color,use_tt);
    }
    return score;
};

int negascout(state_t state, int depth, int alpha, int beta, int color, bool use_tt = false){
    generated++;
    bool first_child = true;
    if (depth == 0 || state.terminal()) {
        return color * state.value();
    };
    // Incializamos el score
    int score = 0;
    // Incializamos una variable para saber si esta jugando white o black
    bool actual = color == 1; 
    // Childs tendra los nodos hijos del nodo state que estamos revisando
    vector<int> childs = state.movs_posibles(actual);
    // Si el state tiene hijos que falten revisar
    if (!childs.empty()) { 
        for (int posicion : childs) {
            expanded++;
            // Generamos el siguiente estado en el arreglo
            state_t state_movement = state.move(actual,posicion);
            if (first_child) {
                first_child = false;
                score = -negascout(state_movement,depth-1,-beta,-alpha,-color,use_tt);
            }
            else {
                score = -negascout(state_movement,depth-1,-alpha-1,-alpha,-color,use_tt);
                if (alpha < score && score < beta) {
                    score = -negascout(state_movement,depth-1,-beta,-score,-color,use_tt);
                }
            } 
            alpha = max(alpha,score);
            if (alpha >= beta) {
                break;
            };
        };
    }
    // Si no tiene, tomamos el alpha actual 
    else {
        alpha = -negascout(state,depth-1,-beta,-alpha,-color,use_tt);
    }
    return alpha;
};

int main(int argc, const char **argv) {
    state_t pv[128];
    int npv = 0;
    for( int i = 0; PV[i] != -1; ++i ) ++npv;

    int algorithm = 0;
    if( argc > 1 ) algorithm = atoi(argv[1]);
    bool use_tt = argc > 2;

    // Extract principal variation of the game
    state_t state;
    cout << "Extracting principal variation (PV) with " << npv << " plays ... " << flush;
    for( int i = 0; PV[i] != -1; ++i ) {
        bool player = i % 2 == 0; // black moves first!
        int pos = PV[i];
        pv[npv - i] = state;
        state = state.move(player, pos);
    }
    pv[0] = state;
    cout << "done!" << endl;

#if 0
    // print principal variation
    for( int i = 0; i <= npv; ++i )
        cout << pv[npv - i];
#endif

    // Print name of algorithm
    cout << "Algorithm: ";
    if( algorithm == 1 )
        cout << "Negamax (minmax version)";
    else if( algorithm == 2 )
        cout << "Negamax (alpha-beta version)";
    else if( algorithm == 3 )
        cout << "Scout";
    else if( algorithm == 4 )
        cout << "Negascout";
    cout << (use_tt ? " w/ transposition table" : "") << endl;

    // Run algorithm along PV (bacwards)
    cout << "Moving along PV:" << endl;
    for( int i = 0; i <= npv; ++i ) {
        //cout << pv[i];
        int value = 0;
        TTable[0].clear();
        TTable[1].clear();
        float start_time = Utils::read_time_in_seconds();
        expanded = 0;
        generated = 0;
        int color = i % 2 == 1 ? 1 : -1;
        try {
            if( algorithm == 1 ) {
                value = negamax(pv[i], 33, color, use_tt);
            } else if( algorithm == 2 ) {
                value = negamax(pv[i], 33, -200, 200, color, use_tt);
            } else if( algorithm == 3 ) {
                value = scout(pv[i], 33, color, use_tt);
            } else if( algorithm == 4 ) {
                value = negascout(pv[i], 33, -200, 200, color, use_tt);
            }
        } catch( const bad_alloc &e ) {
            cout << "size TT[0]: size=" << TTable[0].size() << ", #buckets=" << TTable[0].bucket_count() << endl;
            cout << "size TT[1]: size=" << TTable[1].size() << ", #buckets=" << TTable[1].bucket_count() << endl;
            use_tt = false;
        }

        float elapsed_time = Utils::read_time_in_seconds() - start_time;

        cout << npv + 1 - i << ". " << (color == 1 ? "Black" : "White") << " moves: "
             << "value=" << color * value
             << ", #expanded=" << expanded
             << ", #generated=" << generated
             << ", seconds=" << elapsed_time
             << ", #generated/second=" << generated/elapsed_time
             << endl;
    }

    return 0;
}

