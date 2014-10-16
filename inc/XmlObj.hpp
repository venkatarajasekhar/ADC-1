#ifndef XMLOBJ_HPP
#define XMLOBJ_HPP

class	XmlObj {
    public:
        XmlObj(const string &filename);
        ~XmlObj();

        Initialize();

    private:
        string filename;
        std::vector<XmlObj*> need;
        TestObj tests;
        LessonObj lesson;
};

#endif // XMLOBJ_HPP
