/* taken from http://community.coresecurity.com/~gera/ProgrammingPearls/InlineEgg.html#example2 */

int main() {
    char buf[1024];

    read(0,buf,1024);
    // no idea what this does, but looks cool :)
    ((void(*)())buf)();
}
