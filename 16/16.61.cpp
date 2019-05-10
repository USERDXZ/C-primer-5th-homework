#include <memory>
using namespace std;

template <typename T, typename... Args> 
shared_ptr<T> make_shared(Args&&... args){
    return shared_ptr<T>(new T(forward<Args>(args)...));
}