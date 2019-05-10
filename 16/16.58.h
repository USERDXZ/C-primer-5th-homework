class StrVec{
public:
    template <typename... Args> void emplace_back(Args&&...);
};

template <typename... Args> 
inline
void StrVec::emplace_back(Args&&... args){
    chk_n_alloc();
    alloc.construct(first_free++, forward<Args>(args)...);
}

template <typename T> class Vec{
public:
    template <typename... Args> void emplace_back(Args&&...);
};

template <typename T>
template <typename... Args>
inline
void Vec<T>::emplace_back(Args&&... args){
    chk_n_alloc();
    alloc.construct(first_free++, forward<Args>(args)...);
}