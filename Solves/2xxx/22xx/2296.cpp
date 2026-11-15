auto IO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class TextEditor {

public:
    string left;
    string right;

    TextEditor() {
    }

    void addText(string text) {
        left += text;
    }

    int deleteText(int k) {
        int n = left.size();
        int r = min(k, n);
        left.resize(n - r);
        return r;
    }

    string cursorLeft(int k) {
        int n = left.size();
        int cnt = min(k, n);

        while (cnt--) {
            right.push_back(left.back());
            left.pop_back();
        }

        n = left.size();
        int pos = max(0, n - 10);

        return left.substr(pos);
    }

    string cursorRight(int k) {
        int n = right.size();
        int cnt = min(k, n);

        while (cnt--) {
            left.push_back(right.back());
            right.pop_back();
        }

        n = left.size();
        int pos = max(0, n - 10);

        return left.substr(pos);
    }
};
