#include <iostream>
#include <vector>
#include <string>
#include <sstream>

struct Hano {
    Hano(const char *name, int cnt):_m_cnt(cnt), _m_cur_size(0), _m_name(name) {
        vals.resize(cnt, 0);
    }
    void SetVals() {
        for(int i = 1; i <= _m_cnt; i++) {
            vals[i - 1] = _m_cnt - i + 1;
        }
        _m_cur_size = _m_cnt;
    }
    int Fetch(std::stringstream &ss) {
        if (_m_cur_size < 1) {
            ss << "0 " << _m_name << " ";
            return 0;
        }
        _m_cur_size -= 1;
        ss << vals[_m_cur_size] << " " << _m_name << " ";
        return vals[_m_cur_size];
    }
    void Add(int val, std::stringstream &ss) {
        vals[_m_cur_size] = val;
        _m_cur_size += 1;
        ss << _m_name;
    }
    int Size() {
        return _m_cur_size;
    }
    std::vector<int> vals;
    int _m_cnt;
    int _m_cur_size;
    std::string _m_name;
};

void hano_move(Hano &from, Hano &tmp, Hano &to, int count) {
    if (from.Size() == 0 || count == 0) {
        return;
    }
    if (from.Size() > 1) {
        hano_move(from, to, tmp, count - 1);
    }

    std::stringstream ss;
    to.Add(from.Fetch(ss), ss);
    std::cout << ss.str() << std::endl;

    hano_move(tmp, from, to, count - 1);
    return;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }
    int cnt = std::stoi(argv[1]);
    std::cout << "cnt=" << cnt << std::endl;
    Hano A("A", cnt);
    Hano B("B", cnt);
    Hano C("C", cnt);
    A.SetVals();
    hano_move(A, B, C, cnt);
    return 0;
}
