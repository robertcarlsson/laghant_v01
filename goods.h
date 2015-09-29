
// A subpart of Goods, will be used as a character and interger: ex: A20, B3
struct shelf;

// Representing the good you can type in and work with
struct Goods;


// Will be used for adding good to the array of goods, where ware is a temporary good
// index and savedgoods is used for looking for wrong shelves, index indicating
// where the array is at the moment
void add_good(struct Goods *ware, int index, struct Goods *savedgoods);

// ware is the pointer for the Goods that should be changed
// index and savedgoods are used for the shelfie function
void edit_good(struct Goods *ware, int index, struct Goods *savedgoods);

// Writes the product that ware points at
void print_good(struct Goods *ware);

// Simular to print_good, made for the edit_good function
void print_good_edit(struct Goods *ware);

// Makes you type and retype a letter and number for placement in the warehouse
// it may not be a ware of different type at same place
void shelfie(struct Goods *array, struct shelf *temp, int index);

// Used in shelfie to look in the array for the 
bool shelfcheck(struct Goods *array, struct shelf *temp, char letter, char number, int index);
