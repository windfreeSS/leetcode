// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    bool has_ahead_next;
    int ahead_next_val;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        has_ahead_next = false; 
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if(has_ahead_next)
        {
            return ahead_next_val;
        }
        ahead_next_val = next();
        has_ahead_next = true;
        return ahead_next_val;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if(has_ahead_next)
        {
            has_ahead_next = false;
            return ahead_next_val;
        }
        ahead_next_val = Iterator::next();
        return ahead_next_val;
    }

    bool hasNext() const {
        if(has_ahead_next)
        {
            return true;
        }
        return Iterator::hasNext();
    }
};