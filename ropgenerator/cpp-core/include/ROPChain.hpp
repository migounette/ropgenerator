#ifndef ROPCHAIN_H
#define ROPCHAIN_H

#include "Expression.hpp"
#include "Gadget.hpp"
#include <vector>
using std::vector;
#include <string>
using std::string;  
#include <sstream>
using std::stringstream; 

class ROPChain{
    vector<int> _chain;
    vector<addr_t> _padding_values;  // Padding number n is stored in _chain 
                                    // as -n-1
    vector<string> _padding_comments; 
    vector<bool> _padding_offsets; // If an offset should be added to the padding
    int _len; 
    int _nb_gadgets; 
    int _nb_instr, _nb_instr_ir;
    public: 
        //Constructor
        ROPChain(); 
        // Accessors
        int len();
        int nb_gadgets(); 
        int nb_instr(); 
        int nb_instr_ir(); 
        vector<int>& chain();
        vector<addr_t>& padding_values();
        vector<string>& padding_comments();
        vector<bool>& padding_offsets();
        // Modifiers
        void add_gadget(int g);
        void add_padding(addr_t value, int n=1,  string comment="Padding", bool offset=false);
        void add_chain(ROPChain* other);
        // Sort
        bool lthan(ROPChain* other); 
        // IO
        string to_str_console(int octets, vector<unsigned char> bad_bytes); 
        string to_str_python(int octets, vector<unsigned char> bad_bytes, bool init, bool no_tab); 
        // Assign 
        void copy_from(ROPChain* other);
}; 

#endif 
