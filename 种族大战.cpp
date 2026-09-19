#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <windows.h>

using namespace std;

void aa(int c)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, c);
}

void bb() { aa(7); }

const int cc = 3;
const int dd = 5;
const int ee = 6;
const int ff = 4;

struct A
{
    int m = 0;
    int n = 0;
    int o = 0;
    int p = 0;
    char q = 'a';
    bool r = true;
    bool s = false;
    bool t = false;
    int u = 0;
    int v = 0;
    char b[4] = {' ', ' ', ' ', ' '};
    bool weakened = false;
    bool fear = false;
};

A a[cc][dd];
vector<A> b;
vector<A> c;
int turnCount = 1;
int playerKillCount = 0;
int aiKillCount = 0;
int playerRaceBranch = 0;
int aiRaceBranch = 0;
int d = 1;
int e = 1;
int f = 1;
int g = 1;
string h = "游戏开始！";
int i = 0;
int j = 0;
int k = 1;
int racePlayer = 1;
int raceAI = 1;
int hqPlayerMax = 20;
int hqAIMax = 20;
bool firstDeployUsed = false;
bool aiFirstDeployUsed = false;
int turnSide = 1;
int activePlayer = 1;
int frozen[cc][dd] = {0};
int stunned[cc][dd] = {0};
int silent[cc][dd] = {0};
int mad[cc][dd] = {0};
int bleeding[cc][dd] = {0};
int armor[cc][dd] = {0};
int spirit[cc][dd] = {0};
int rage[cc][dd] = {0};
int command[cc][dd] = {0};
int greedy[cc][dd] = {0};
int firstStrike[cc][dd] = {0};
int precise[cc][dd] = {0};
int hidden[cc][dd] = {0};
int taunt[cc][dd] = {0};
int power[cc][dd] = {0};
int lightning[cc][dd] = {0};
int pierce[cc][dd] = {0};
int riot[cc][dd] = {0};
int poisonStack[cc][dd] = {0};
int burnStack[cc][dd] = {0};

mt19937 rng((unsigned)time(nullptr));

char fa(char z)
{
    if(z >= 'A' && z <= 'Z') return z + 32;
    return z;
}

int fb(char z)
{
    z = fa(z);
    if(z == 'q') return -1;
    if(z == 'w') return 2;
    if(z == 'e') return 1;
    if(z == 'r') return 0;
    return -1;
}

int fc(const string& z)
{
    int w = 0;
    for(size_t v = 0; v < z.size();)
    {
        unsigned char u = z[v];
        if(u < 0x80)              { w += 1; v += 1; }
        else if((u >> 5) == 0x06) { w += 1; v += 2; }
        else if((u >> 4) == 0x0E) { w += 2; v += 3; }
        else if((u >> 3) == 0x1E) { w += 2; v += 4; }
        else                      { w += 1; v += 1; }
    }
    return w;
}

string fd(const string& z, int w)
{
    int v = fc(z);
    if(v >= w) return z;
    int u = (w - v) / 2;
    int t = w - v - u;
    return string(u, ' ') + z + string(t, ' ');
}

bool hasBuff(const A& z, char ch)
{
    for(int i = 0; i < 4; ++i)
        if(z.b[i] == ch) return true;
    return false;
}

void clearBuff(A& z, char ch)
{
    for(int i = 0; i < 4; ++i)
        if(z.b[i] == ch) z.b[i] = ' ';
}

void addBuffToCard(int row, int col, char ch)
{
    if(a[row][col].r) return;
    if(hasBuff(a[row][col], ch)) return;
    for(int bi = 0; bi < 4; ++bi)
        if(a[row][col].b[bi] == ' ') { a[row][col].b[bi] = ch; return; }
}

void removeBuffFromCard(int row, int col, char ch)
{
    if(a[row][col].r) return;
    for(int bi = 0; bi < 4; ++bi)
        if(a[row][col].b[bi] == ch) a[row][col].b[bi] = ' ';
}

vector<string> fe(const A& z)
{
    vector<string> v(ff, string(ee, ' '));
    if(z.r) return v;

    if(z.q == 'H')
    {
        v[2][2] = 'H';
        string u = to_string(z.p);
        if(u.length() == 1) v[3][ee - 1] = u[0];
        else if(u.length() == 2) { v[3][ee - 2] = u[0]; v[3][ee - 1] = u[1]; }
        else { v[3][ee - 3] = u[0]; v[3][ee - 2] = u[1]; v[3][ee - 1] = u[2]; }
        return v;
    }

    int vm = z.m; if(vm < 0) vm = 0; if(vm > 9) vm = 9;
    int vn = z.n; if(vn < 0) vn = 0; if(vn > 9) vn = 9;
    int vo = z.o; if(vo < 0) vo = 0; if(vo > 9) vo = 9;
    int vp = z.p; if(vp < 0) vp = 0; if(vp > 9) vp = 9;
    v[1][0] = char('0' + vm);
    v[1][ee - 1] = char('0' + vn);
    v[2][2] = z.q;
    v[3][0] = char('0' + vo);
    v[3][ee - 1] = char('0' + vp);

    for(int bi = 0; bi < 4; ++bi)
        if(z.b[bi] != ' ') { v[0][0] = z.b[bi]; break; }

    return v;
}

string fg(int z)
{
    string v = "+";
    for(int u = 0; u < z; ++u) v += string(ee, '-') + "+";
    return v;
}

A fh(int z, int y)
{
    A x;
    x.r = false;
    x.s = false;
    x.t = false;
    x.u = k;
    x.weakened = false;
    x.fear = false;

    int w = z + (rng() % 3) - 1;
    if(w < 1) w = 1;
    if(y == 2) w += 1;

    int v = rng() % 5;
    if(v == 0) x.q = 'a';
    else if(v == 1) x.q = 'b';
    else if(v == 2) x.q = 'c';
    else if(v == 3) x.q = 'd';
    else x.q = 'f';

    int u = (y == 2) ? 1 : 0;

    switch(x.q)
    {
        case 'a':
            x.m = 1 + rng() % w;
            x.n = rng() % 2;
            x.o = 2 + rng() % 3 + u;
            x.p = 3 + rng() % 4 + u;
            break;
        case 'b':
            x.m = 1 + rng() % w;
            x.n = rng() % 2;
            x.o = 3 + rng() % 4 + u;
            x.p = 1 + rng() % 3 + u;
            break;
        case 'c':
            x.m = 1 + rng() % w;
            x.n = rng() % 2;
            x.o = 2 + rng() % 3 + u;
            x.p = 1 + rng() % 3 + u;
            break;
        case 'd':
            x.m = 1 + rng() % w;
            x.n = rng() % 2;
            x.o = 1 + rng() % 2 + u;
            x.p = 2 + rng() % 3 + u;
            break;
        case 'f':
            x.m = 1 + rng() % w;
            x.n = rng() % 2;
            x.o = 1 + rng() % 2 + u;
            x.p = 1 + rng() % 3 + u;
            break;
    }

    if(rng() % 100 < 30)
    {
        char bf = ' ';
        if(x.q == 'a') bf = '!';
        else if(x.q == 'b') bf = '?';
        else if(x.q == 'c') bf = '-';
        else if(x.q == 'd') bf = '/';
        else if(x.q == 'f') bf = '^';
        int pos = rng() % 4;
        x.b[pos] = bf;
    }

    if(y == 0)
    {
        if(racePlayer == 2)
        {
            if(x.q == 'b') x.o += 1;
            if(x.q == 'a' || x.q == 'f') x.p -= 1;
        }
        else if(racePlayer == 3) { x.p += 1; x.n += 1; }
        else if(racePlayer == 4) { x.p -= 1; }
        else if(racePlayer == 6) { x.o -= 1; }
        else if(racePlayer == 7) { if(!hasBuff(x, '%')) for(int bb2 = 0; bb2 < 4; ++bb2) if(x.b[bb2] == ' ') { x.b[bb2] = '%'; break; } }
        else if(racePlayer == 8)
        {
            if(playerRaceBranch == 1) x.p += 1;
            else if(playerRaceBranch == 2) x.o += 1;
            else if(playerRaceBranch == 3) for(int bb2 = 0; bb2 < 4; ++bb2) if(x.b[bb2] == ' ') { x.b[bb2] = '_'; break; }
            else if(playerRaceBranch == 4) { x.p += 1; x.o += 1; }
        }
        else if(racePlayer == 9)
        {
            x.p -= 1;
            if(rng() % 100 < 30) for(int bb2 = 0; bb2 < 4; ++bb2) if(x.b[bb2] == ' ') { x.b[bb2] = '*'; break; }
        }
    }
    else if(y == 2)
    {
        if(raceAI == 2)
        {
            if(x.q == 'b') x.o += 1;
            if(x.q == 'a' || x.q == 'f') x.p -= 1;
        }
        else if(raceAI == 3) { x.p += 1; x.n += 1; }
        else if(raceAI == 4) { x.p -= 1; }
        else if(raceAI == 7) { if(!hasBuff(x, '%')) for(int bb2 = 0; bb2 < 4; ++bb2) if(x.b[bb2] == ' ') { x.b[bb2] = '%'; break; } }
        else if(raceAI == 8)
        {
            if(aiRaceBranch == 1) x.p += 1;
            else if(aiRaceBranch == 2) x.o += 1;
            else if(aiRaceBranch == 3) for(int bb2 = 0; bb2 < 4; ++bb2) if(x.b[bb2] == ' ') { x.b[bb2] = '_'; break; }
            else if(aiRaceBranch == 4) { x.p += 1; x.o += 1; }
        }
        else if(raceAI == 9)
        {
            x.p -= 1;
            if(rng() % 100 < 30) for(int bb2 = 0; bb2 < 4; ++bb2) if(x.b[bb2] == ' ') { x.b[bb2] = '*'; break; }
        }
    }
    if(x.m < 0) x.m = 0;
    if(x.n < 0) x.n = 0;
    if(x.o < 1) x.o = 1;
    if(x.p < 1) x.p = 1;
    if(x.m > 9) x.m = 9;
    if(x.n > 9) x.n = 9;
    if(x.o > 9) x.o = 9;
    if(x.p > 9) x.p = 9;
    return x;
}

A fh_action(int y)
{
    A x;
    x.r = false;
    x.s = false;
    x.t = false;
    x.u = k;
    x.weakened = false;
    x.fear = false;
    x.o = 0;
    x.p = 0;
    x.n = 0;
    for(int i = 0; i < 4; ++i) x.b[i] = ' ';
    int pick = rng() % 5;
    x.q = 'A' + pick;
    x.m = 1 + rng() % 3;
    (void)y;
    return x;
}

void syncBuff(int r, int c)
{
    if(a[r][c].r) return;
    for(int i = 0; i < 4; ++i)
    {
        char ch = a[r][c].b[i];
        if(ch == '!') taunt[r][c] = 1;
        else if(ch == '?') power[r][c] = 1;
        else if(ch == '-') lightning[r][c] = 1;
        else if(ch == '/') pierce[r][c] = 1;
        else if(ch == '^') riot[r][c] = 1;
        else if(ch == '=') armor[r][c] = 1;
        else if(ch == '~') spirit[r][c] = 1;
        else if(ch == '@') rage[r][c] = 1;
        else if(ch == '#') command[r][c] = 1;
        else if(ch == '$') greedy[r][c] = 1;
        else if(ch == '<') firstStrike[r][c] = 1;
        else if(ch == '>') precise[r][c] = 1;
        else if(ch == '_') hidden[r][c] = 1;
    }
}

void onUnitKilled(int r, int c)
{
    if(a[r][c].r) return;
    int deathRace = (a[r][c].v == 1) ? racePlayer : raceAI;
    int deathSide = a[r][c].v;
    a[r][c].r = true;
    if(deathRace == 6 && rng() % 100 < 50)
    {
        A skeleton;
        skeleton.q = 'a';
        skeleton.o = 1;
        skeleton.p = 1;
        skeleton.m = 0;
        skeleton.n = 0;
        skeleton.r = false;
        skeleton.v = deathSide;
        skeleton.u = k;
        a[r][c] = skeleton;
    }
}

void useActionCard(int cardId, char targetZone, int targetIdx, int srcOwner)
{
    int race = (srcOwner == 1) ? racePlayer : raceAI;
    int branch = (srcOwner == 1) ? playerRaceBranch : aiRaceBranch;
    int row = -1;
    if(targetZone == 'e') row = 1;
    else if(targetZone == 'w') row = 2;
    else if(targetZone == 'r') row = 0;
    string log = "";

    if(race == 1)
    {
        if(cardId == 0)
        {
            int lim = 5 + 1;
            for(int i = 0; i < 2; ++i)
            {
                if(srcOwner == 1 && (int)b.size() < lim)
                {
                    if(rng() % 100 < 30) b.push_back(fh_action(0));
                    else b.push_back(fh(e, 0));
                }
                else if(srcOwner == 2 && (int)c.size() < lim)
                {
                    if(rng() % 100 < 30) c.push_back(fh_action(1));
                    else c.push_back(fh(e, 2));
                }
            }
            log = "征兵令：抽 2 张牌！";
        }
        else if(cardId == 1)
        {
            if(row < 0) log = "方阵冲锋：目标区域无效！";
            else
            {
                for(int c2 = 0; c2 < dd; ++c2)
                    if(!a[row][c2].r && a[row][c2].v == srcOwner)
                    {
                        taunt[row][c2] = 1;
                        addBuffToCard(row, c2, '!');
                    }
                log = "方阵冲锋：该排获得嘲讽！";
            }
        }
        else if(cardId == 2)
        {
            int hqRow = (srcOwner == 1) ? 2 : 0;
            a[hqRow][2].p -= 2;
            if(srcOwner == 1) d += 3;
            else f += 3;
            if(a[hqRow][2].p < 1) a[hqRow][2].p = 1;
            log = "国王税：总部-2血，+3行动点！";
        }
        else if(cardId == 3)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd)
            {
                int c2 = targetIdx - 1;
                if(!a[row][c2].r)
                {
                    a[row][c2].p += 3;
                    a[row][c2].weakened = false;
                    removeBuffFromCard(row, c2, 'W');
                    poisonStack[row][c2] = 0;
                    removeBuffFromCard(row, c2, 'P');
                    bleeding[row][c2] = 0;
                    removeBuffFromCard(row, c2, 'V');
                    log = "战地医院：治疗 3 点并清除负面状态！";
                }
                else log = "战地医院：目标位置无卡牌！";
            }
            else log = "战地医院：目标无效！";
        }
        else if(cardId == 4)
        {
            if(targetZone == 'e' && targetIdx >= 1 && targetIdx <= dd)
            {
                int c2 = targetIdx - 1;
                if(!a[1][c2].r && a[1][c2].v == srcOwner)
                {
                    int backRow = (srcOwner == 1) ? 2 : 0;
                    bool moved = false;
                    for(int w2 = 0; w2 < dd; ++w2)
                    {
                        if(a[backRow][w2].r && !(backRow == 2 && w2 == 2) && !(backRow == 0 && w2 == 2))
                        {
                            a[backRow][w2] = a[1][c2];
                            a[backRow][w2].r = false;
                            a[1][c2].r = true;
                            armor[backRow][w2] = 1;
                            addBuffToCard(backRow, w2, '=');
                            moved = true;
                            log = "战术撤退：撤回后方并获得重甲1！";
                            break;
                        }
                    }
                    if(!moved) log = "战术撤退：后方无空位！";
                }
                else log = "战术撤退：目标无效！";
            }
            else log = "战术撤退：必须指定前线单位！";
        }
    }
    else if(race == 2)
    {
        if(cardId == 0)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd && !a[row][targetIdx - 1].r)
            {
                a[row][targetIdx - 1].p -= 2;
                if(a[row][targetIdx - 1].p <= 0) onUnitKilled(row, targetIdx - 1);
                log = "月华箭：造成 2 点魔法伤害！";
            }
            else log = "月华箭：目标无效！";
        }
        else if(cardId == 1)
        {
            if(row < 0) log = "森林庇护：目标区域无效！";
            else
            {
                for(int c2 = 0; c2 < dd; ++c2)
                    if(!a[row][c2].r && a[row][c2].v == srcOwner)
                    {
                        spirit[row][c2] = 1;
                        addBuffToCard(row, c2, '~');
                    }
                log = "森林庇护：该排获得灵体！";
            }
        }
        else if(cardId == 2)
        {
            if(row < 0) log = "精准齐射：目标区域无效！";
            else
            {
                for(int c2 = 0; c2 < dd; ++c2)
                {
                    if(!a[row][c2].r && a[row][c2].v != srcOwner)
                    {
                        int dmg = 2;
                        if(precise[row][c2] > 0 || hasBuff(a[row][c2], '>')) dmg = 3;
                        a[row][c2].p -= dmg;
                        if(a[row][c2].p <= 0) onUnitKilled(row, c2);
                    }
                }
                log = "精准齐射：该排受到 2 点远程伤害！";
            }
        }
        else if(cardId == 3)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd && !a[row][targetIdx - 1].r)
            {
                int c2 = targetIdx - 1;
                stunned[row][c2] = 1;
                addBuffToCard(row, c2, 'D');
                a[row][c2].weakened = true;
                addBuffToCard(row, c2, 'W');
                log = "藤蔓缠绕：目标眩晕并虚弱！";
            }
            else log = "藤蔓缠绕：目标无效！";
        }
        else if(cardId == 4)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd && !a[row][targetIdx - 1].r)
            {
                int c2 = targetIdx - 1;
                hidden[row][c2] = 1;
                addBuffToCard(row, c2, '_');
                log = "风行步：目标获得隐匿！";
            }
            else log = "风行步：目标无效！";
        }
    }
    else if(race == 3)
    {
        if(cardId == 0)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd && !a[row][targetIdx - 1].r)
            {
                int c2 = targetIdx - 1;
                armor[row][c2] += 2;
                if(armor[row][c2] > 3) armor[row][c2] = 3;
                addBuffToCard(row, c2, '=');
                log = "符文护甲：获得重甲2！";
            }
            else log = "符文护甲：目标无效！";
        }
        else if(cardId == 1)
        {
            if(row < 0) log = "山岳阵线：目标区域无效！";
            else
            {
                for(int c2 = 0; c2 < dd; ++c2)
                    if(!a[row][c2].r && a[row][c2].v == srcOwner)
                    {
                        taunt[row][c2] = 1;
                        addBuffToCard(row, c2, '!');
                        a[row][c2].p += 1;
                    }
                log = "山岳阵线：该排获得嘲讽和生命+1！";
            }
        }
        else if(cardId == 2)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd && !a[row][targetIdx - 1].r)
            {
                int c2 = targetIdx - 1;
                a[row][c2].p -= 3;
                if(armor[row][c2] > 0) armor[row][c2] = 0;
                removeBuffFromCard(row, c2, '=');
                if(a[row][c2].p <= 0) onUnitKilled(row, c2);
                log = "锻炉爆鸣：造成 3 点火焰伤害！";
            }
            else log = "锻炉爆鸣：目标无效！";
        }
        else if(cardId == 3)
        {
            if(row < 0) log = "深矿塌方：目标区域无效！";
            else
            {
                for(int c2 = 0; c2 < dd; ++c2)
                {
                    if(!a[row][c2].r && a[row][c2].v != srcOwner)
                    {
                        a[row][c2].p -= 2;
                        stunned[row][c2] = 1;
                        addBuffToCard(row, c2, 'D');
                        if(a[row][c2].p <= 0) onUnitKilled(row, c2);
                    }
                }
                log = "深矿塌方：该排受到 2 点物理伤害并眩晕！";
            }
        }
        else if(cardId == 4)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd && !a[row][targetIdx - 1].r)
            {
                a[row][targetIdx - 1].o += 1;
                log = "符文铭刻：目标攻击+1！";
            }
            else log = "符文铭刻：目标无效！";
        }
    }
    else if(race == 4)
    {
        if(cardId == 0)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd)
            {
                int tr = row;
                int tc = targetIdx - 1;
                a[tr][tc].p -= 2;
                if(a[tr][tc].p <= 0 && !a[tr][tc].r) onUnitKilled(tr, tc);
                if(tc > 0) { a[tr][tc - 1].p -= 2; if(a[tr][tc - 1].p <= 0 && !a[tr][tc - 1].r) onUnitKilled(tr, tc - 1); }
                if(tc < dd - 1) { a[tr][tc + 1].p -= 2; if(a[tr][tc + 1].p <= 0 && !a[tr][tc + 1].r) onUnitKilled(tr, tc + 1); }
                if(tr > 0) { a[tr - 1][tc].p -= 2; if(a[tr - 1][tc].p <= 0 && !a[tr - 1][tc].r) onUnitKilled(tr - 1, tc); }
                if(tr < cc - 1) { a[tr + 1][tc].p -= 2; if(a[tr + 1][tc].p <= 0 && !a[tr + 1][tc].r) onUnitKilled(tr + 1, tc); }
                log = "炸弹：范围 2 点火焰伤害！";
            }
            else log = "炸弹：目标无效！";
        }
        else if(cardId == 1)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd && !a[row][targetIdx - 1].r)
            {
                a[row][targetIdx - 1].p -= 1;
                if(a[row][targetIdx - 1].p <= 0)
                {
                    onUnitKilled(row, targetIdx - 1);
                    if(srcOwner == 1) d += 2;
                    else f += 2;
                    if(srcOwner == 1 && (int)b.size() < 5) b.push_back(fh(e, 0));
                }
                log = "抢劫：造成 1 点伤害！";
            }
            else log = "抢劫：目标无效！";
        }
        else if(cardId == 2)
        {
            if(srcOwner == 1)
            {
                if((int)b.size() < 5) b.push_back(fh(e, 0));
                log = "地精市场：抽 1 张牌！";
            }
            else
            {
                if((int)c.size() < 5) c.push_back(fh(e, 2));
                log = "地精市场：AI 抽 1 张牌！";
            }
        }
        else if(cardId == 3)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd && !a[row][targetIdx - 1].r)
            {
                int tr = row;
                int tc = targetIdx - 1;
                a[tr][tc].r = true;
                if(tc > 0) { a[tr][tc - 1].p -= 3; if(a[tr][tc - 1].p <= 0 && !a[tr][tc - 1].r) onUnitKilled(tr, tc - 1); }
                if(tc < dd - 1) { a[tr][tc + 1].p -= 3; if(a[tr][tc + 1].p <= 0 && !a[tr][tc + 1].r) onUnitKilled(tr, tc + 1); }
                if(tr > 0) { a[tr - 1][tc].p -= 3; if(a[tr - 1][tc].p <= 0 && !a[tr - 1][tc].r) onUnitKilled(tr - 1, tc); }
                if(tr < cc - 1) { a[tr + 1][tc].p -= 3; if(a[tr + 1][tc].p <= 0 && !a[tr + 1][tc].r) onUnitKilled(tr + 1, tc); }
                log = "自爆冲锋：范围 3 点火焰伤害！";
            }
            else log = "自爆冲锋：目标无效！";
        }
        else if(cardId == 4)
        {
            if(row < 0) log = "混乱烟雾：目标区域无效！";
            else
            {
                for(int c2 = 0; c2 < dd; ++c2)
                    if(!a[row][c2].r && a[row][c2].v != srcOwner)
                    {
                        mad[row][c2] = 1;
                        addBuffToCard(row, c2, 'M');
                    }
                log = "混乱烟雾：该排获得疯狂！";
            }
        }
    }
    else if(race == 5)
    {
        if(cardId == 0)
        {
            if(row < 0) log = "战吼：目标区域无效！";
            else
            {
                for(int c2 = 0; c2 < dd; ++c2)
                    if(!a[row][c2].r && a[row][c2].v == srcOwner)
                    {
                        command[row][c2] = 1;
                        addBuffToCard(row, c2, '#');
                    }
                log = "战吼：该排获得统御！";
            }
        }
        else if(cardId == 1)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd && !a[row][targetIdx - 1].r)
            {
                a[row][targetIdx - 1].o += 2;
                log = "狂怒冲锋：目标攻击+2！";
            }
            else log = "狂怒冲锋：目标无效！";
        }
        else if(cardId == 2)
        {
            int hqRow = (srcOwner == 1) ? 2 : 0;
            a[hqRow][2].p -= 2;
            if(srcOwner == 1) d += 3;
            else f += 3;
            if(a[hqRow][2].p < 1) a[hqRow][2].p = 1;
            log = "血祭：总部-2血换+3行动点！";
        }
        else if(cardId == 3)
        {
            int hqRow = (srcOwner == 1) ? 2 : 0;
            a[hqRow][2].p += 4;
            log = "先祖之魂：总部回复 4 点生命！";
        }
        else if(cardId == 4)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd && !a[row][targetIdx - 1].r)
            {
                int c2 = targetIdx - 1;
                a[row][c2].p -= 2;
                a[row][c2].weakened = true;
                addBuffToCard(row, c2, 'W');
                if(a[row][c2].p <= 0) onUnitKilled(row, c2);
                log = "破甲投斧：造成 2 点伤害并虚弱！";
            }
            else log = "破甲投斧：目标无效！";
        }
    }
    else if(race == 6)
    {
        if(cardId == 0)
        {
            int backRow = (srcOwner == 1) ? 2 : 0;
            for(int c2 = 0; c2 < dd; ++c2)
            {
                if(a[backRow][c2].r && !(backRow == 2 && c2 == 2) && !(backRow == 0 && c2 == 2))
                {
                    A skel;
                    skel.q = 'a';
                    skel.o = 1;
                    skel.p = 1;
                    skel.m = 0;
                    skel.n = 0;
                    skel.r = false;
                    skel.v = srcOwner;
                    skel.u = k;
                    a[backRow][c2] = skel;
                    log = "亡者复生：召唤 1/1 骷髅！";
                    break;
                }
            }
            if(log == "") log = "亡者复生：后排无空位！";
        }
        else if(cardId == 1)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd && !a[row][targetIdx - 1].r)
            {
                int hp = a[row][targetIdx - 1].p;
                a[row][targetIdx - 1].r = true;
                int tr = row;
                int tc = targetIdx - 1;
                if(tc > 0) { a[tr][tc - 1].p -= hp; if(a[tr][tc - 1].p <= 0 && !a[tr][tc - 1].r) onUnitKilled(tr, tc - 1); }
                if(tc < dd - 1) { a[tr][tc + 1].p -= hp; if(a[tr][tc + 1].p <= 0 && !a[tr][tc + 1].r) onUnitKilled(tr, tc + 1); }
                if(tr > 0) { a[tr - 1][tc].p -= hp; if(a[tr - 1][tc].p <= 0 && !a[tr - 1][tc].r) onUnitKilled(tr - 1, tc); }
                if(tr < cc - 1) { a[tr + 1][tc].p -= hp; if(a[tr + 1][tc].p <= 0 && !a[tr + 1][tc].r) onUnitKilled(tr + 1, tc); }
                log = "尸爆：牺牲单位造成范围伤害！";
            }
            else log = "尸爆：目标无效！";
        }
        else if(cardId == 2)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd && !a[row][targetIdx - 1].r)
            {
                a[row][targetIdx - 1].p -= 2;
                int hqRow = (srcOwner == 1) ? 2 : 0;
                a[hqRow][2].p += 2;
                if(a[row][targetIdx - 1].p <= 0) onUnitKilled(row, targetIdx - 1);
                log = "灵魂虹吸：造成 2 点伤害并回复 2 点！";
            }
            else log = "灵魂虹吸：目标无效！";
        }
        else if(cardId == 3)
        {
            int backRow = (srcOwner == 1) ? 2 : 0;
            int count = 0;
            for(int c2 = 0; c2 < dd && count < 2; ++c2)
            {
                if(a[backRow][c2].r && !(backRow == 2 && c2 == 2) && !(backRow == 0 && c2 == 2))
                {
                    A skel;
                    skel.q = 'a';
                    skel.o = 1;
                    skel.p = 1;
                    skel.m = 0;
                    skel.n = 0;
                    skel.r = false;
                    skel.v = srcOwner;
                    skel.u = k;
                    a[backRow][c2] = skel;
                    count++;
                }
            }
            log = "墓园之门：召唤 " + to_string(count) + " 个骷髅！";
        }
        else if(cardId == 4)
        {
            if(row < 0) log = "瘟疫云：目标区域无效！";
            else
            {
                for(int c2 = 0; c2 < dd; ++c2)
                {
                    if(!a[row][c2].r && a[row][c2].v != srcOwner)
                    {
                        poisonStack[row][c2] += 2;
                        addBuffToCard(row, c2, 'P');
                        a[row][c2].weakened = true;
                        addBuffToCard(row, c2, 'W');
                    }
                }
                log = "瘟疫云：该排中毒2层并虚弱！";
            }
        }
    }
    else if(race == 7)
    {
        if(cardId == 0)
        {
            int hqRow = (srcOwner == 1) ? 2 : 0;
            a[hqRow][2].p -= 2;
            if(a[hqRow][2].p < 1) a[hqRow][2].p = 1;
            if(srcOwner == 1) d += 3;
            else f += 3;
            log = "血祭：总部-2血换+3行动点！";
        }
        else if(cardId == 1)
        {
            for(int r = 0; r < cc; ++r)
                for(int c2 = 0; c2 < dd; ++c2)
                    if(!a[r][c2].r && a[r][c2].v == srcOwner)
                    {
                        a[r][c2].o += 1;
                        addBuffToCard(r, c2, '%');
                    }
            log = "血月：全体血族攻击+1并获吸血！";
        }
        else if(cardId == 2)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd && !a[row][targetIdx - 1].r)
            {
                int c2 = targetIdx - 1;
                addBuffToCard(row, c2, '%');
                rage[row][c2] = 1;
                addBuffToCard(row, c2, '@');
                log = "鲜血契约：目标获吸血和血怒！";
            }
            else log = "鲜血契约：目标无效！";
        }
        else if(cardId == 3)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd && !a[row][targetIdx - 1].r)
            {
                int c2 = targetIdx - 1;
                hidden[row][c2] = 1;
                addBuffToCard(row, c2, '_');
                log = "暗夜突袭：目标获得隐匿！";
            }
            else log = "暗夜突袭：目标无效！";
        }
        else if(cardId == 4)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd && !a[row][targetIdx - 1].r)
            {
                a[row][targetIdx - 1].p -= 2;
                int hqRow = (srcOwner == 1) ? 2 : 0;
                a[hqRow][2].p += 1;
                if(a[row][targetIdx - 1].p <= 0) onUnitKilled(row, targetIdx - 1);
                log = "吸血箭：造成 2 点伤害并回复 1 点！";
            }
            else log = "吸血箭：目标无效！";
        }
    }
    else if(race == 8)
    {
        if(cardId == 0)
        {
            if(srcOwner == 1 && (int)b.size() < 5) b.push_back(fh(e, 0));
            else if(srcOwner == 2 && (int)c.size() < 5) c.push_back(fh(e, 2));
            log = "神谕：查看牌库顶并抽 1 张！";
        }
        else if(cardId == 1)
        {
            for(int r = 0; r < cc; ++r)
                for(int c2 = 0; c2 < dd; ++c2)
                    if(!a[r][c2].r && a[r][c2].v == srcOwner) a[r][c2].p += 2;
            log = "圣光普照：全体治疗 2 点！";
        }
        else if(cardId == 2)
        {
            for(int r = 0; r < cc; ++r)
                for(int c2 = 0; c2 < dd; ++c2)
                    if(!a[r][c2].r && a[r][c2].v == srcOwner)
                    {
                        if(branch == 1) a[r][c2].p += 3;
                        else if(branch == 2) a[r][c2].o += 2;
                        else if(branch == 3) { a[r][c2].p += 1; a[r][c2].s = true; }
                        else if(branch == 4) { a[r][c2].p += 1; a[r][c2].o += 1; }
                    }
            log = "日月同辉：全体获得分支效果！";
        }
        else if(cardId == 3)
        {
            if(row < 0) log = "元素风暴：目标区域无效！";
            else
            {
                for(int c2 = 0; c2 < dd; ++c2)
                {
                    if(!a[row][c2].r && a[row][c2].v != srcOwner)
                    {
                        a[row][c2].p -= 2;
                        burnStack[row][c2] += 1;
                        addBuffToCard(row, c2, 'B');
                        frozen[row][c2] = 1;
                        addBuffToCard(row, c2, 'F');
                        if(a[row][c2].p <= 0) onUnitKilled(row, c2);
                    }
                }
                log = "元素风暴：该排受到 2 伤并附加燃烧+冻结！";
            }
        }
        else if(cardId == 4)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd && !a[row][targetIdx - 1].r)
            {
                int c2 = targetIdx - 1;
                armor[row][c2] += 1;
                addBuffToCard(row, c2, '=');
                log = "圣盾术：目标获得重甲1！";
            }
            else log = "圣盾术：目标无效！";
        }
    }
    else if(race == 9)
    {
        if(cardId == 0)
        {
            int frontRow = 1;
            for(int c2 = 0; c2 < dd; ++c2)
            {
                if(a[frontRow][c2].r)
                {
                    A tentacle;
                    tentacle.q = 'a';
                    tentacle.o = 2;
                    tentacle.p = 2;
                    tentacle.m = 0;
                    tentacle.n = 0;
                    tentacle.r = false;
                    tentacle.v = srcOwner;
                    tentacle.u = k;
                    tentacle.b[0] = '*';
                    a[frontRow][c2] = tentacle;
                    log = "深渊召唤：召唤 2/2 触手！";
                    break;
                }
            }
            if(log == "") log = "深渊召唤：前线无空位！";
        }
        else if(cardId == 1)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd && !a[row][targetIdx - 1].r)
            {
                int c2 = targetIdx - 1;
                mad[row][c2] = 1;
                addBuffToCard(row, c2, 'M');
                log = "疯狂低语：目标获得疯狂！";
            }
            else log = "疯狂低语：目标无效！";
        }
        else if(cardId == 2)
        {
            if(row < 0) log = "不可名状：目标区域无效！";
            else
            {
                for(int c2 = 0; c2 < dd; ++c2)
                {
                    if(!a[row][c2].r && a[row][c2].v != srcOwner)
                    {
                        a[row][c2].fear = true;
                        addBuffToCard(row, c2, '*');
                        a[row][c2].weakened = true;
                        addBuffToCard(row, c2, 'W');
                        if(a[row][c2].o > 4) { silent[row][c2] = 1; addBuffToCard(row, c2, 'S'); }
                    }
                }
                log = "不可名状：该排恐惧+虚弱！";
            }
        }
        else if(cardId == 3)
        {
            int backRow = (srcOwner == 1) ? 2 : 0;
            int placed = 0;
            for(int c2 = 0; c2 < dd - 1; ++c2)
            {
                if(a[backRow][c2].r && a[backRow][c2 + 1].r && !(backRow == 2 && (c2 == 2 || c2 == 1)) && !(backRow == 0 && (c2 == 2 || c2 == 1)))
                {
                    A star;
                    star.q = 'a';
                    star.o = 4;
                    star.p = 6;
                    star.m = 0;
                    star.n = 0;
                    star.r = false;
                    star.v = srcOwner;
                    star.u = k;
                    star.b[0] = '*';
                    a[backRow][c2] = star;
                    placed = 1;
                    log = "星之眷族：召唤 4/6 眷族！";
                    break;
                }
            }
            if(!placed) log = "星之眷族：后方无连续2空格！";
        }
        else if(cardId == 4)
        {
            if(row >= 0 && targetIdx >= 1 && targetIdx <= dd && !a[row][targetIdx - 1].r)
            {
                int c2 = targetIdx - 1;
                poisonStack[row][c2] += 1;
                addBuffToCard(row, c2, 'P');
                log = "污染蔓延：目标中毒1层！";
            }
            else log = "污染蔓延：目标无效！";
        }
    }
    h = log;
}

void fi()
{
    for(int v = 0; v < cc; ++v)
        for(int u = 0; u < dd; ++u)
            if(!a[v][u].r)
            {
                a[v][u].s = false;
                a[v][u].t = false;
            }
}

void resetStatus()
{
    for(int r = 0; r < cc; ++r)
        for(int c2 = 0; c2 < dd; ++c2)
        {
            armor[r][c2] = 0;
            spirit[r][c2] = 0;
        }
}

void resolveStatus()
{
    for(int v = 0; v < cc; ++v)
    {
        for(int u = 0; u < dd; ++u)
        {
            if(a[v][u].r) continue;
            int poison = poisonStack[v][u];
            int burn = burnStack[v][u];
            for(int i = 0; i < 4; ++i)
            {
                if(a[v][u].b[i] == 'P') poison++;
                if(a[v][u].b[i] == 'B') burn++;
            }
            int fireAmp = 1;
            if(v == 0 && (raceAI == 2 || raceAI == 8)) fireAmp = 2;
            if(v >= 1 && (racePlayer == 2 || racePlayer == 8)) fireAmp = 2;
            if(poison > 0) a[v][u].p -= poison;
            if(burn > 0) a[v][u].p -= burn * fireAmp;
            int bleed = bleeding[v][u];
            if(bleed > 0) a[v][u].p -= bleed;
            if(a[v][u].p <= 0 && a[v][u].q != 'H')
            {
                onUnitKilled(v, u);
            }
        }
    }
}

bool fj(int v, int u, int t, int s, char q)
{
    int w = abs(u - s);
    int z = abs(v - t);
    if(q == 'b') return true;
    if(q == 'a' || q == 'f') return (w + z == 1);
    if(q == 'c' || q == 'd') return (w + z <= 2);
    return false;
}

void ga()
{
    int v = (int)b.size();
    if(v == 0) { cout << "(手牌为空)" << endl; return; }
    cout << fg(v) << endl;
    for(int u = 0; u < ff; ++u)
    {
        string w = "|";
        for(int t = 0; t < v; ++t)
        {
            vector<string> s = fe(b[t]);
            w += s[u];
            w += "|";
        }
        cout << w << endl;
    }
    cout << fg(v) << endl;
    for(int u = 0; u < v; ++u) cout << " " << fd("[" + to_string(u + 1) + "]", ee);
    cout << endl;
}

void gb()
{
    system("cls");
    cout << "【指令格式】 [区域] [序号] [操作] [目标区域] [目标序号]" << endl;
    cout << "区域: q(手牌) w(后方) e(前线) r(敌方后方) | 操作: 移动(w/e/r) 攻击(a) 行动卡(u)" << endl;
    cout << "示例: q 2 w 2 (部署), e 2 a r 3 (攻击), q 2 u e 3 (行动卡), f (结束回合),输入 ? 呼出游戏介绍" << endl;
    aa(12);
    cout << "AI 手牌: " << c.size() << " 张" << endl;
    bb();
    vector<string> v =
    {
        " _____________________",
        "|      战斗面板       |",
        "|_____________________|",
        "|  AI   行动点: " + to_string(f) + "     |",
        "|  AI   补给值: " + to_string(g) + "     |",
        "|_____________________|",
        "|  玩家 行动点: " + to_string(d) + "     |",
        "|  玩家 补给值: " + to_string(e) + "     |",
        "|_____________________|"
    };

    vector<string> u =
    {
        " _____________________",
        "|  [卡牌数字位置说明] |",
        "|  左上:部署 右上:移动|",
        "|  左下:攻击 右下:生命|",
        "|_____________________|",
        "|  [职业与攻击范围]   |",
        "|  a战士  : 上下左右  |",
        "|  b弓手  : 全图      |",
        "|  c法师  : 距离2格   |",
        "|  d牧师  : 距离2格   |",
        "|  f农民  : 上下左右  |",
        "|  H总部  : 固定位置  |",
        "|  (摧毁敌方总部获胜)|",
        "|_____________________|"
    };

    vector<string> t;
    int s = max(v.size(), u.size());
    for(int x = 0; x < s; ++x)
    {
        string z = (x < (int)v.size()) ? v[x] : string(23, ' ');
        string y = (x < (int)u.size()) ? u[x] : string(23, ' ');
        t.push_back(z + "   " + y);
    }

    cout << fg(dd) << "   " << (t.size() > 0 ? t[0] : "") << endl;
    int x = 1;
    for(int r = 0; r < cc; ++r)
    {
        for(int c2 = 0; c2 < ff; ++c2)
        {
            cout << "|";
            for(int y = 0; y < dd; ++y)
            {
                vector<string> z = fe(a[r][y]);
                string q = z[c2];
                if(c2 == 0 && !a[r][y].r)
                {
                    if(taunt[r][y] > 0 || hasBuff(a[r][y], '!')) q[0] = '!';
                    else if(power[r][y] > 0 || hasBuff(a[r][y], '?')) q[0] = '?';
                    else if(lightning[r][y] > 0 || hasBuff(a[r][y], '-')) q[0] = '-';
                    else if(pierce[r][y] > 0 || hasBuff(a[r][y], '/')) q[0] = '/';
                    else if(riot[r][y] > 0 || hasBuff(a[r][y], '^')) q[0] = '^';
                    else if(armor[r][y] > 0 || hasBuff(a[r][y], '=')) q[0] = '=';
                    else if(spirit[r][y] > 0 || hasBuff(a[r][y], '~')) q[0] = '~';
                    else if(rage[r][y] > 0 || hasBuff(a[r][y], '@')) q[0] = '@';
                    else if(command[r][y] > 0 || hasBuff(a[r][y], '#')) q[0] = '#';
                    else if(greedy[r][y] > 0 || hasBuff(a[r][y], '$')) q[0] = '$';
                    else if(firstStrike[r][y] > 0 || hasBuff(a[r][y], '<')) q[0] = '<';
                    else if(precise[r][y] > 0 || hasBuff(a[r][y], '>')) q[0] = '>';
                    else if(hidden[r][y] > 0 || hasBuff(a[r][y], '_')) q[0] = '_';
                    else if(poisonStack[r][y] > 0 || hasBuff(a[r][y], 'P')) q[0] = 'P';
                    else if(burnStack[r][y] > 0 || hasBuff(a[r][y], 'B')) q[0] = 'B';
                    else if(frozen[r][y] > 0 || hasBuff(a[r][y], 'F')) q[0] = 'F';
                    else if(stunned[r][y] > 0 || hasBuff(a[r][y], 'D')) q[0] = 'D';
                    else if(silent[r][y] > 0 || hasBuff(a[r][y], 'S')) q[0] = 'S';
                    else if(mad[r][y] > 0 || hasBuff(a[r][y], 'M')) q[0] = 'M';
                    else if(bleeding[r][y] > 0 || hasBuff(a[r][y], 'V')) q[0] = 'V';
                    else if(a[r][y].fear || hasBuff(a[r][y], '*')) q[0] = '*';
                    else if(a[r][y].weakened || hasBuff(a[r][y], 'W')) q[0] = 'W';
                }
                if(!a[r][y].r)
                {
                    if(a[r][y].v == 1) aa(9);
                    else if(a[r][y].v == 2) aa(12);
                    else bb();
                    cout << q;
                    bb();
                }
                else cout << q;
                cout << "|";
            }
            if(x < (int)t.size()) cout << "   " << t[x++];
            cout << endl;
        }
        cout << fg(dd);
        if(x < (int)t.size()) cout << "   " << t[x++];
        cout << endl;
    }

    while(x < (int)t.size()) cout << string(dd * (ee + 1) + 1, ' ') << "   " << t[x++] << endl;

    if(i == 0)
    {
        if(turnSide == 1) cout << "玩家1 手牌 (" << b.size() << " 张):" << endl;
        else cout << "玩家2 手牌 (" << b.size() << " 张):" << endl;
    }
    else cout << "你的手牌 (" << b.size() << " 张):" << endl;
    aa(9);
    ga();
    bb();

    cout << "【提示】 " << h << endl;
}

void gc()
{
    for(int v = 0; v < cc; ++v)
        for(int u = 0; u < dd; ++u)
        {
            a[v][u].r = true;
            a[v][u].s = false;
            a[v][u].t = false;
            a[v][u].v = 0;
            a[v][u].weakened = false;
            a[v][u].fear = false;
            for(int t = 0; t < 4; ++t) a[v][u].b[t] = ' ';
        }
    resetStatus();

    A v;
    v.q = 'H';
    v.p = hqPlayerMax;
    v.r = false;
    v.v = 1;
    a[2][2] = v;

    A u;
    u.q = 'H';
    u.p = hqAIMax;
    u.r = false;
    u.v = 2;
    a[0][2] = u;

    b.clear();
    c.clear();
    k = 1;
    for(int t = 0; t < 3; ++t)
    {
        b.push_back(fh(1, 0));
        c.push_back(fh(1, 2));
    }
    b.push_back(fh_action(0));
    c.push_back(fh_action(1));

    d = 1;
    e = 1;
    f = 1;
    g = 1;
    if(racePlayer == 4) e += 1;
    if(raceAI == 4) g += 1;
    d = e;
    f = g;
    firstDeployUsed = false;
    aiFirstDeployUsed = false;
    turnCount = 1;
    turnSide = 1;
    activePlayer = 1;
    playerKillCount = 0;
    aiKillCount = 0;
}

void gd(char v, int u, char t, int s)
{
    int w = fb(v);
    int z = fb(t);
    if(z == -1) { h = "错误：目标区域不能是手牌！"; return; }
    if(w == -1)
    {
        if(t != 'w' && t != 'W') { h = "错误：手牌只能部署到玩家后方（w）！"; return; }
        if(s < 1 || s > dd) { h = "错误：目标列数无效（1-5）！"; return; }
        if(z == 2 && s == 3) { h = "错误：此位置是总部，无法部署卡牌！"; return; }
        if(u < 1 || u > (int)b.size()) { h = "错误：手牌序号无效！"; return; }
        if(!a[z][s - 1].r) { h = "错误：目标位置已有卡牌！"; return; }
        A& x = b[u - 1];
        int cost = x.m;
        int currentRace = (activePlayer == 1) ? racePlayer : raceAI;
        bool& usedFlag = (activePlayer == 1) ? firstDeployUsed : aiFirstDeployUsed;
        if(currentRace == 1 && !usedFlag && cost > 0) { cost -= 1; usedFlag = true; }
        if(d < cost) { h = "错误：行动点不足，无法部署！"; return; }
        d -= cost;
        int owner = activePlayer;
        a[z][s - 1] = x;
        a[z][s - 1].r = false;
        a[z][s - 1].s = false;
        a[z][s - 1].t = false;
        a[z][s - 1].u = k;
        a[z][s - 1].v = owner;
        if(x.q == 'b')
        {
            int myRace = (owner == 1) ? racePlayer : raceAI;
            bool isHomeRow = (owner == 1 && z == 2) || (owner == 2 && z == 0);
            if(myRace == 2 && isHomeRow) hidden[z][s - 1] = 1;
        }
        syncBuff(z, s - 1);
        b.erase(b.begin() + u - 1);
        h = "部署成功！";
    }
    else
    {
        if(u < 1 || u > dd || s < 1 || s > dd) { h = "错误：坐标越界！"; return; }
        A& x = a[w][u - 1];
        if(x.r) { h = "错误：源位置没有卡牌！"; return; }
        if(x.v != activePlayer) { h = "错误：不能操作敌方单位！"; return; }
        if(x.q == 'H') { h = "错误：总部无法移动！"; return; }
        if(stunned[w][u - 1] > 0 || hasBuff(x, 'D')) { h = "错误：该单位处于眩晕状态！"; return; }
        if(x.q != 'a' && x.u == k) { h = "错误：该单位刚部署，本回合无法移动！"; return; }
        if(x.q == 'a') { if(x.t) { h = "错误：战士攻击后本回合无法移动！"; return; } }
        else { if(x.s || x.t) { h = "错误：该单位本回合已经行动过了！"; return; } }
        int y = abs((u - 1) - (s - 1));
        int v2 = abs(w - z);
        if(y + v2 != 1) { h = "错误：只能上下左右移动！"; return; }
        if(z == 0 && s == 3) { h = "错误：不能移动到敌方总部位置！"; return; }
        if(z == 2 && s == 3) { h = "错误：不能移动到己方总部位置！"; return; }
        int extra = 0;
        if(frozen[w][u - 1] > 0 || hasBuff(x, 'F')) extra = 1;
        if(d < x.n + extra)
        {
            if(extra > 0) h = "错误：被冻结，需要多花 1 点行动点！";
            else h = "错误：行动点不足，无法移动！";
            return;
        }
        if(!a[z][s - 1].r) { h = "错误：目标位置已有卡牌！"; return; }
        d -= (x.n + extra);
        int owner = x.v;
        A moved = x;
        a[z][s - 1] = moved;
        a[z][s - 1].r = false;
        a[w][u - 1].r = true;
        a[z][s - 1].v = owner;
        a[z][s - 1].s = true;
        syncBuff(z, s - 1);
        if(hasBuff(a[z][s - 1], '_'))
        {
            hidden[z][s - 1] = 0;
            clearBuff(a[z][s - 1], '_');
        }
        h = "移动成功！";
    }
}

void ge(char v, int u, char t, int s)
{
    int w = fb(v);
    int z = fb(t);
    if(w == -1) { h = "错误：手牌不能攻击！"; return; }
    if(z == -1) { h = "错误：不能攻击手牌！"; return; }
    if(u < 1 || u > dd || s < 1 || s > dd) { h = "错误：坐标越界！"; return; }
    A& x = a[w][u - 1];
    if(x.r) { h = "错误：攻击方位置没有卡牌！"; return; }
    if(x.v != activePlayer) { h = "错误：不能操作敌方单位！"; return; }
    if(x.q == 'H') { h = "错误：总部无法攻击！"; return; }
    if(stunned[w][u - 1] > 0 || hasBuff(x, 'D')) { h = "错误：该单位处于眩晕状态！"; return; }
    if((silent[w][u - 1] > 0 || hasBuff(x, 'S')) && (x.q == 'c' || x.q == 'd')) { h = "错误：该单位被沉默，无法使用技能！"; return; }
    if(x.q != 'a' && x.u == k) { h = "错误：该单位刚部署，本回合无法攻击！"; return; }
    if(x.q == 'a') { if(x.t) { h = "错误：战士本回合已经攻击过了！"; return; } }
    else { if(x.s || x.t) { h = "错误：该单位本回合已经行动过了！"; return; } }

    string prefix = "";
    if(mad[w][u - 1] > 0 || hasBuff(x, 'M'))
    {
        vector<pair<int,int>> candidates;
        for(int r2 = 0; r2 < cc; ++r2)
            for(int c2 = 0; c2 < dd; ++c2)
                if(!a[r2][c2].r && a[r2][c2].v != x.v && a[r2][c2].q != 'H'
                    && !(hidden[r2][c2] > 0 || hasBuff(a[r2][c2], '_'))
                    && fj(w, u - 1, r2, c2, x.q))
                    candidates.push_back({r2, c2});
        if(!candidates.empty())
        {
            int pick = rng() % candidates.size();
            z = candidates[pick].first;
            s = candidates[pick].second + 1;
            prefix = "疯狂！攻击目标被随机重定向。";
        }
    }
    A& y = a[z][s - 1];
    if(y.r) { h = "错误：目标位置没有卡牌！"; return; }
    if(y.q == 'H') { }
    else if(hidden[z][s - 1] > 0 || hasBuff(y, '_')) { h = "错误：目标处于隐匿状态，无法被选中！"; return; }
    if((x.fear || hasBuff(x, '*')) && y.q == 'f') { h = "错误：该单位处于恐惧状态，无法攻击农民！"; return; }
    bool isEnemy = (y.v != x.v);
    bool u2 = fj(w, u - 1, z, s - 1, x.q);
    if(!u2) { h = "错误：目标不在攻击范围内！"; return; }
    bool hasTaunt = false;
    for(int r = 0; r < cc; ++r)
    {
        for(int c2 = 0; c2 < dd; ++c2)
            if(!a[r][c2].r && a[r][c2].v != x.v)
            {
                bool isT = (taunt[r][c2] > 0 || hasBuff(a[r][c2], '!'));
                if(isT && fj(w, u - 1, r, c2, x.q)) { hasTaunt = true; break; }
            }
        if(hasTaunt) break;
    }
    bool selfPrecise = (precise[w][u - 1] > 0 || hasBuff(x, '>'));
    bool targetIsTaunt = (taunt[z][s - 1] > 0 || hasBuff(y, '!'));
    if(hasTaunt && !targetIsTaunt && !selfPrecise) { h = "错误：目标区域存在嘲讽单位，你必须优先攻击嘲讽单位！"; return; }
    if(x.q == 'd')
    {
        if(isEnemy) { h = "错误：牧师只能治疗友方，不能攻击敌方！"; return; }
        if(silent[w][u - 1] > 0 || hasBuff(x, 'S')) { h = "错误：该牧师被沉默，无法治疗！"; return; }
        if(y.weakened || hasBuff(y, 'W')) { h = "错误：目标被虚弱，无法接受治疗！"; return; }
    }
    else { if(!isEnemy) { h = "错误：该职业只能攻击敌方，不能攻击友方！"; return; } }
    int extra = 0;
    if(frozen[w][u - 1] > 0 || hasBuff(x, 'F')) extra = 1;
    if(d < x.n + extra)
    {
        if(extra > 0) h = "错误：被冻结，需要多花 1 点行动点！";
        else h = "错误：行动点不足，无法攻击/治疗！";
        return;
    }
    d -= (x.n + extra);
    x.t = true;

    if(x.q == 'd')
    {
        if(pierce[w][u - 1] > 0 || hasBuff(x, '/')) { y.weakened = true; addBuffToCard(z, s - 1, 'W'); }
        int heal = x.o;
        int targetRace = (y.v == 1) ? racePlayer : raceAI;
        if(targetRace == 6) heal = (heal + 1) / 2;
        if(y.q == 'H' && y.p + heal > (y.v == 1 ? hqPlayerMax : hqAIMax))
            heal = (y.v == 1 ? hqPlayerMax : hqAIMax) - y.p;
        y.p += heal;
        h = prefix + "牧师治疗成功！友方生命值恢复了 " + to_string(heal) + " 点。";
    }
    else
    {
        int dmg = x.o;
        if((precise[w][u - 1] > 0 || hasBuff(x, '>')) && (x.q == 'b' || x.q == 'c')) dmg += 1;
        if(y.weakened || hasBuff(y, 'W')) { dmg = dmg * 3 / 2; if(dmg < 1) dmg = 1; }
        if((power[w][u - 1] > 0 || hasBuff(x, '?')) && y.p < x.o) dmg *= 2;
        if(command[w][u - 1] > 0) dmg += command[w][u - 1];
        if(rage[w][u - 1] > 0) dmg += rage[w][u - 1];
        int armorVal = armor[z][s - 1];
        if(hasBuff(y, '=') && armorVal < 1) armorVal = 1;
        if(armorVal > 0) { if(armorVal > 3) armorVal = 3; dmg -= armorVal; if(dmg < 1) dmg = 1; }
        bool spiritY = (spirit[z][s - 1] > 0 || hasBuff(y, '~'));
        if(spiritY)
        {
            if(x.q == 'c' || x.q == 'd') dmg = dmg * 3 / 2;
            else { dmg = dmg / 2; if(dmg < 1) dmg = 1; }
        }
        if(firstStrike[w][u - 1] > 0 || hasBuff(x, '<'))
        {
            y.p -= 1;
            if(y.p <= 0) onUnitKilled(z, s - 1);
            h += " 先攻造成1点伤害！";
        }
        if(!y.r)
        {
            if(hasBuff(x, '?')) { if(y.p < x.o) dmg *= 2; }
            int defRace = (y.v == 1) ? racePlayer : raceAI;
            if(hasBuff(x, '^')) { if(!(y.q != 'H' && defRace == 3)) { y.fear = true; addBuffToCard(z, s - 1, '*'); } }
            if(riot[w][u - 1] > 0) { if(!(y.q != 'H' && defRace == 3)) { y.fear = true; addBuffToCard(z, s - 1, '*'); } }
            if(pierce[w][u - 1] > 0 || hasBuff(x, '/')) { y.weakened = true; addBuffToCard(z, s - 1, 'W'); }
            y.p -= dmg;
            if(hasBuff(x, '%')) x.p += dmg / 2;
            int targetRace = (y.v == 1) ? racePlayer : raceAI;
            if(targetRace == 5 && y.q != 'H')
            {
                rage[z][s - 1] += 1;
                if(rage[z][s - 1] > 3) rage[z][s - 1] = 3;
                addBuffToCard(z, s - 1, '@');
            }
            if(x.v == 1 && racePlayer == 7) x.p += dmg / 2;
            if(x.v == 2 && raceAI == 7) x.p += dmg / 2;
            if(raceAI == 9 && x.v == 2 && rng() % 100 < 25)
            {
                int nz = rng() % cc;
                int ns = rng() % dd;
                if(!a[nz][ns].r && a[nz][ns].v == 1)
                {
                    a[nz][ns].p -= dmg;
                    if(a[nz][ns].p <= 0) onUnitKilled(nz, ns);
                    h += " 疯狂低语！";
                }
            }
            if(racePlayer == 9 && x.v == 1 && rng() % 100 < 25)
            {
                int nz = rng() % cc;
                int ns = rng() % dd;
                if(!a[nz][ns].r && a[nz][ns].v == 2)
                {
                    a[nz][ns].p -= dmg;
                    if(a[nz][ns].p <= 0) onUnitKilled(nz, ns);
                    h += " 疯狂低语！";
                }
            }
        }
        if(y.q == 'H') h = prefix + "攻击敌方总部！造成 " + to_string(dmg) + " 点伤害！剩余生命：" + to_string(y.p);
        else h = prefix + "攻击造成 " + to_string(dmg) + " 点伤害！";
        bool hasLightning = (lightning[w][u - 1] > 0 || hasBuff(x, '-'));
        if(hasLightning)
        {
            int splash = x.o / 2;
            if(splash < 1) splash = 1;
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            for(int i = 0; i < 4; ++i)
            {
                int nx = z + dx[i];
                int ny = s - 1 + dy[i];
                if(nx >= 0 && nx < cc && ny >= 0 && ny < dd)
                    if(!a[nx][ny].r && a[nx][ny].v != x.v)
                    {
                        a[nx][ny].p -= splash;
                        if(a[nx][ny].p <= 0) onUnitKilled(nx, ny);
                    }
            }
        }
        if(y.p <= 0 && y.q != 'H')
        {
            h += " 目标被击破！";
            onUnitKilled(z, s - 1);
            if(x.v == 1)
            {
                playerKillCount++;
                if(racePlayer == 4) d += 1;
                if(racePlayer == 6) x.p += 1;
                if(racePlayer == 7) x.p += 2;
            }
            else if(x.v == 2)
            {
                aiKillCount++;
                if(raceAI == 4) f += 1;
                if(raceAI == 6) x.p += 1;
                if(raceAI == 7) x.p += 2;
            }
            if(greedy[w][u - 1] > 0 || hasBuff(x, '$'))
            {
                if(x.v == 1) d += 1;
                else if(x.v == 2) f += 1;
            }
        }
    }
    if(bleeding[w][u - 1] > 0 || hasBuff(x, 'V'))
    {
        int bd = bleeding[w][u - 1];
        if(bd < 1) bd = 1;
        x.p -= bd;
        if(x.p <= 0) onUnitKilled(w, u - 1);
    }
    if(x.q != 'a' && x.q != 'f' && x.q != 'H')
    {
        hidden[w][u - 1] = 0;
        clearBuff(x, '_');
    }
    if((x.q == 'a' || x.q == 'f') && !y.r && y.p > 0 && y.q != 'H')
    {
        bool t2 = fj(z, s - 1, w, u - 1, y.q);
        if(t2)
        {
            x.p -= y.o;
            h += " 目标反击，造成 " + to_string(y.o) + " 点伤害！";
            if(x.p <= 0)
            {
                h += " 攻击方被击破！";
                onUnitKilled(w, u - 1);
            }
        }
    }
}

void gf()
{
    f = g;

    int myTotalHP = a[0][2].p;
    for(int r = 0; r < 2; ++r)
        for(int cc2 = 0; cc2 < dd; ++cc2)
            if(!a[r][cc2].r && a[r][cc2].q != 'H') myTotalHP += a[r][cc2].p;
    int enemyTotalHP = a[2][2].p;
    for(int r = 1; r < cc; ++r)
        for(int cc2 = 0; cc2 < dd; ++cc2)
            if(!a[r][cc2].r && a[r][cc2].q != 'H') enemyTotalHP += a[r][cc2].p;
    bool defenseMode = (myTotalHP < enemyTotalHP / 2);
    bool aggressive = (a[2][2].p <= 5);

    for(int i = 0; i < (int)c.size(); ++i)
    {
        if(c[i].q >= 'A' && c[i].q <= 'I')
        {
            if(f >= c[i].m)
            {
                int cid = c[i].q - 'A';
                int myRace = raceAI;
                char tz = 'e';
                int ti = 0;
                if(myRace == 1)
                {
                    if(cid == 0) { tz = ' '; ti = 0; }
                    else if(cid == 1) { tz = 'r'; ti = 0; }
                    else if(cid == 2) { tz = ' '; ti = 0; }
                    else
                    {
                        for(int r = 1; r < cc; ++r)
                            for(int tc = 0; tc < dd; ++tc)
                                if(!a[r][tc].r && a[r][tc].v == 2)
                                { tz = (r == 1) ? 'e' : 'r'; ti = tc + 1; break; }
                        if(ti == 0) { tz = 'e'; ti = 1; }
                    }
                }
                else if(myRace == 2)
                {
                    tz = 'w';
                    for(int tc = 0; tc < dd; ++tc)
                        if(!a[2][tc].r && a[2][tc].v == 2) { ti = tc + 1; break; }
                    if(ti == 0) ti = 1;
                    if(cid == 2) tz = 'r';
                }
                else if(myRace == 3)
                {
                    tz = 'w';
                    for(int tc = 0; tc < dd; ++tc)
                        if(!a[2][tc].r && a[2][tc].v == 2) { ti = tc + 1; break; }
                    if(ti == 0) ti = 1;
                }
                else if(myRace == 4)
                {
                    for(int tc = 0; tc < dd; ++tc)
                        if(!a[2][tc].r && a[2][tc].v == 1) { ti = tc + 1; break; }
                    if(ti == 0) ti = 1;
                    tz = 'e';
                }
                else if(myRace == 5)
                {
                    tz = 'w';
                    for(int tc = 0; tc < dd; ++tc)
                        if(!a[2][tc].r && a[2][tc].v == 2) { ti = tc + 1; break; }
                    if(ti == 0) ti = 1;
                }
                else if(myRace == 6)
                {
                    if(cid == 0 || cid == 3) { tz = 'r'; ti = 0; }
                    else
                    {
                        for(int r = 1; r < cc; ++r)
                            for(int tc = 0; tc < dd; ++tc)
                                if(!a[r][tc].r && a[r][tc].v == 1)
                                { tz = (r == 1) ? 'e' : 'w'; ti = tc + 1; break; }
                        if(ti == 0) { tz = 'e'; ti = 1; }
                    }
                }
                else if(myRace == 7)
                {
                    if(cid == 0 || cid == 1) { tz = ' '; ti = 0; }
                    else
                    {
                        for(int r = 1; r < cc; ++r)
                            for(int tc = 0; tc < dd; ++tc)
                                if(!a[r][tc].r && a[r][tc].v == 2)
                                { tz = (r == 1) ? 'e' : 'w'; ti = tc + 1; break; }
                        if(ti == 0) { tz = 'e'; ti = 1; }
                    }
                }
                else if(myRace == 8)
                {
                    if(cid == 0) { tz = ' '; ti = 0; }
                    else if(cid == 1 || cid == 2) { tz = 'w'; ti = 0; }
                    else if(cid == 3) { tz = 'r'; ti = 0; }
                    else
                    {
                        for(int r = 1; r < cc; ++r)
                            for(int tc = 0; tc < dd; ++tc)
                                if(!a[r][tc].r && a[r][tc].v == 2)
                                { tz = (r == 1) ? 'e' : 'w'; ti = tc + 1; break; }
                        if(ti == 0) { tz = 'e'; ti = 1; }
                    }
                }
                else if(myRace == 9)
                {
                    if(cid == 0 || cid == 3) { tz = 'r'; ti = 0; }
                    else
                    {
                        for(int r = 1; r < cc; ++r)
                            for(int tc = 0; tc < dd; ++tc)
                                if(!a[r][tc].r && a[r][tc].v == 2)
                                { tz = (r == 1) ? 'e' : 'w'; ti = tc + 1; break; }
                        if(ti == 0) { tz = 'e'; ti = 1; }
                    }
                }
                f -= c[i].m;
                c.erase(c.begin() + i);
                useActionCard(cid, tz, ti, 2);
                break;
            }
        }
    }
    string v = "AI行动：";
    int u = 0;
    for(int t = 0; t < dd; ++t) if(!a[0][t].r && a[0][t].q == 'f') u++;
    if((int)c.size() < 5 + u) c.push_back(fh(g, 2));
    bool t = false;
    for(int s = 0; s < (int)c.size(); ++s)
    {
        if(f >= c[s].m)
        {
            vector<int> w = {0, 1, 3, 4, 2};
            if(j == 0) shuffle(w.begin(), w.end(), rng);
            for(int x : w)
            {
                if(x == 2) continue;
                if(a[0][x].r)
                {
                    int cost = c[s].m;
                    if(raceAI == 1 && !aiFirstDeployUsed && cost > 0) { cost -= 1; aiFirstDeployUsed = true; }
                    f -= cost;
                    a[0][x] = c[s];
                    a[0][x].r = false;
                    a[0][x].s = false;
                    a[0][x].t = false;
                    a[0][x].u = k;
                    a[0][x].v = 2;
                    if(a[0][x].q == 'b' && raceAI == 2) hidden[0][x] = 1;
                    syncBuff(0, x);
                    c.erase(c.begin() + s);
                    v += "AI部署单位到后排第" + to_string(x + 1) + "列。";
                    t = true;
                    break;
                }
            }
            if(t) break;
        }
    }
    for(int x = 0; x < dd; ++x)
    {
        if(x == 2) continue;
        if(!a[0][x].r && a[0][x].q != 'H' && f >= a[0][x].n)
        {
            if(stunned[0][x] > 0 || hasBuff(a[0][x], 'D')) continue;
            if(a[0][x].u == k) continue;
            if(a[0][x].q == 'a' && a[0][x].t) continue;
            if(a[0][x].q != 'a' && (a[0][x].s || a[0][x].t)) continue;
            if(a[1][x].r)
            {
                int extra = (frozen[0][x] > 0 || hasBuff(a[0][x], 'F')) ? 1 : 0;
                f -= (a[0][x].n + extra);
                A moved = a[0][x];
                a[1][x] = moved;
                a[1][x].r = false;
                a[0][x].r = true;
                a[1][x].s = true;
                a[1][x].v = 2;
                syncBuff(1, x);
                if(hasBuff(a[1][x], '_'))
                {
                    hidden[1][x] = 0;
                    clearBuff(a[1][x], '_');
                }
                v += "AI移动单位到前线第" + to_string(x + 1) + "列。";
                break;
            }
        }
    }
    vector<pair<int, int>> y;
    for(int x = 0; x < 2; ++x)
        for(int z = 0; z < dd; ++z)
            if(!a[x][z].r && a[x][z].q != 'H') y.push_back({x, z});
    if(j == 0) shuffle(y.begin(), y.end(), rng);
    for(auto& z : y)
    {
        int x = z.first;
        int w = z.second;
        if(a[x][w].r || a[x][w].q == 'H') continue;
        if(stunned[x][w] > 0 || hasBuff(a[x][w], 'D')) continue;
        if((silent[x][w] > 0 || hasBuff(a[x][w], 'S')) && (a[x][w].q == 'c' || a[x][w].q == 'd')) continue;
        if(a[x][w].q != 'a' && a[x][w].u == k) continue;
        if(a[x][w].q == 'a') { if(a[x][w].t) continue; }
        else { if(a[x][w].s || a[x][w].t) continue; }
        int extra = (frozen[x][w] > 0 || hasBuff(a[x][w], 'F')) ? 1 : 0;
        if(f < a[x][w].n + extra) continue;
        if(a[x][w].q == 'd')
        {
            for(int tr = 0; tr < cc; ++tr)
            {
                for(int tc = 0; tc < dd; ++tc)
                {
                    if(tr == 0) continue;
                    if(a[tr][tc].r) continue;
                    if(a[tr][tc].v != 2) continue;
                    if(a[tr][tc].p >= 9) continue;
                    if(fj(x, w, tr, tc, 'd'))
                    {
                        if(a[tr][tc].weakened || hasBuff(a[tr][tc], 'W')) continue;
                        if(f < a[x][w].n + extra) continue;
                        f -= (a[x][w].n + extra);
                        if(a[x][w].b[0] == '/' || a[x][w].b[1] == '/' || a[x][w].b[2] == '/' || a[x][w].b[3] == '/')
                        {
                            a[tr][tc].weakened = true;
                            addBuffToCard(tr, tc, 'W');
                        }
                        a[tr][tc].p += a[x][w].o;
                        a[x][w].t = true;
                        v += "AI牧师治疗友方。";
                        break;
                    }
                }
                if(a[x][w].t) break;
            }
            continue;
        }
        vector<pair<int, int>> s;
        bool hasTaunt = false;
        for(int r = 1; r < cc; ++r)
        {
            for(int c2 = 0; c2 < dd; ++c2)
                if(!a[r][c2].r && a[r][c2].v == 1)
                {
                    bool isT = (taunt[r][c2] > 0 || hasBuff(a[r][c2], '!'));
                    if(isT && fj(x, w, r, c2, a[x][w].q)) { hasTaunt = true; break; }
                }
            if(hasTaunt) break;
        }
        bool selfPrecise = (precise[x][w] > 0 || hasBuff(a[x][w], '>'));
        if(hasTaunt && !selfPrecise)
        {
            for(int r = 1; r < cc; ++r)
                for(int c2 = 0; c2 < dd; ++c2)
                    if(!a[r][c2].r && a[r][c2].v == 1)
                    {
                        bool isT = (taunt[r][c2] > 0 || hasBuff(a[r][c2], '!'));
                        if(isT && fj(x, w, r, c2, a[x][w].q)) s.push_back({r, c2});
                    }
        }
        else
        {
            if(fj(x, w, 2, 2, a[x][w].q)) s.push_back({2, 2});
            for(int t2 = 1; t2 < 3; ++t2)
                for(int r = 0; r < dd; ++r)
                {
                    if(t2 == 2 && r == 2) continue;
                    if(a[t2][r].r) continue;
                    if(a[t2][r].v == 2) continue;
                    if(hidden[t2][r] > 0 || hasBuff(a[t2][r], '_')) continue;
                    if(fj(x, w, t2, r, a[x][w].q)) s.push_back({t2, r});
                }
        }
        if(s.empty()) continue;
        pair<int, int> u;
        if(j == 2)
        {
            bool q = false;
            for(auto& p : s) if(p.first == 2 && p.second == 2) { u = p; q = true; break; }
            if(!q)
            {
                int o = -1;
                for(auto& p : s) if(a[p.first][p.second].o > o) { o = a[p.first][p.second].o; u = p; }
            }
            if(a[u.first][u.second].q != 'H' && a[u.first][u.second].p > 0)
            {
                bool p = fj(u.first, u.second, x, w, a[u.first][u.second].q);
                if(p && a[x][w].p <= a[u.first][u.second].o) continue;
            }
        }
        else if(aggressive && j >= 1)
        {
            bool hqFound = false;
            for(auto& p : s) if(p.first == 2 && p.second == 2) { u = p; hqFound = true; break; }
            if(!hqFound) u = s[rng() % s.size()];
        }
        else if(defenseMode && j >= 1)
        {
            int maxAtk = -1;
            u = s[0];
            for(auto& p : s) if(a[p.first][p.second].o > maxAtk) { maxAtk = a[p.first][p.second].o; u = p; }
        }
        else u = s[rng() % s.size()];
        int t = u.first;
        int r = u.second;
        f -= (a[x][w].n + extra);
        int dmg = a[x][w].o;
        if((precise[x][w] > 0 || hasBuff(a[x][w], '>')) && (a[x][w].q == 'b' || a[x][w].q == 'c')) dmg += 1;
        if(command[x][w] > 0) dmg += command[x][w];
        if(rage[x][w] > 0) dmg += rage[x][w];
        if(a[t][r].weakened || hasBuff(a[t][r], 'W')) { dmg = dmg * 3 / 2; if(dmg < 1) dmg = 1; }
        if(hasBuff(a[x][w], '?') && a[t][r].p < a[x][w].o) dmg *= 2;
        if(hasBuff(a[x][w], '^'))
        {
            int defRace = (a[t][r].v == 1) ? racePlayer : raceAI;
            if(defRace != 3) { a[t][r].fear = true; addBuffToCard(t, r, '*'); }
        }
        int armorVal = armor[t][r];
        if(hasBuff(a[t][r], '=') && armorVal < 1) armorVal = 1;
        if(armorVal > 0) { if(armorVal > 3) armorVal = 3; dmg -= armorVal; if(dmg < 1) dmg = 1; }
        bool spiritY = (spirit[t][r] > 0 || hasBuff(a[t][r], '~'));
        if(spiritY)
        {
            if(a[x][w].q == 'c' || a[x][w].q == 'd') dmg = dmg * 3 / 2;
            else { dmg = dmg / 2; if(dmg < 1) dmg = 1; }
        }
        if(firstStrike[x][w] > 0 || hasBuff(a[x][w], '<'))
        {
            a[t][r].p -= 1;
            if(a[t][r].p <= 0 && !(t == 2 && r == 2)) onUnitKilled(t, r);
            v += " 先攻造成1点伤害！";
        }
        if(racePlayer == 9 && a[x][w].v == 1 && rng() % 100 < 25)
        {
            int nz = rng() % cc;
            int ns = rng() % dd;
            if(!a[nz][ns].r && a[nz][ns].v == 2)
            {
                a[nz][ns].p -= dmg;
                if(a[nz][ns].p <= 0) onUnitKilled(nz, ns);
                v += " 疯狂低语！";
            }
        }
        a[t][r].p -= dmg;
        if(hasBuff(a[x][w], '%')) a[x][w].p += dmg / 2;
        if(t == 2 && r == 2) v += "AI攻击玩家总部！造成 " + to_string(dmg) + " 点伤害！";
        else v += "AI攻击玩家第" + to_string(t + 1) + "行第" + to_string(r + 1) + "列。造成 " + to_string(dmg) + " 点伤害！";
        bool hasLightning = (lightning[x][w] > 0 || hasBuff(a[x][w], '-'));
        if(hasLightning)
        {
            int splash = a[x][w].o / 2;
            if(splash < 1) splash = 1;
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            for(int i = 0; i < 4; ++i)
            {
                int nx = t + dx[i];
                int ny = r + dy[i];
                if(nx >= 0 && nx < cc && ny >= 0 && ny < dd)
                    if(!a[nx][ny].r && a[nx][ny].v == 1)
                    {
                        a[nx][ny].p -= splash;
                        if(a[nx][ny].p <= 0) onUnitKilled(nx, ny);
                    }
            }
        }
        if(a[x][w].b[0] == '/' || a[x][w].b[1] == '/' || a[x][w].b[2] == '/' || a[x][w].b[3] == '/')
        {
            a[t][r].weakened = true;
            addBuffToCard(t, r, 'W');
        }
        if(a[t][r].p <= 0)
        {
            if(!(t == 2 && r == 2))
            {
                onUnitKilled(t, r);
                v += "玩家卡牌被击破！";
                aiKillCount++;
                if(raceAI == 4) f += 1;
                if(raceAI == 6) a[x][w].p += 1;
                if(raceAI == 7) a[x][w].p += 2;
            }
        }
        a[x][w].t = true;
        if(bleeding[x][w] > 0 || hasBuff(a[x][w], 'V'))
        {
            int bd = bleeding[x][w];
            if(bd < 1) bd = 1;
            a[x][w].p -= bd;
            if(a[x][w].p <= 0) onUnitKilled(x, w);
        }
        if(a[x][w].q != 'a' && a[x][w].q != 'f' && a[x][w].q != 'H')
        {
            hidden[x][w] = 0;
            clearBuff(a[x][w], '_');
        }
        if((a[x][w].q == 'a' || a[x][w].q == 'f') && !a[t][r].r && a[t][r].p > 0 && a[t][r].q != 'H')
        {
            bool o = fj(t, r, x, w, a[t][r].q);
            if(o)
            {
                a[x][w].p -= a[t][r].o;
                v += " 玩家单位反击，造成 " + to_string(a[t][r].o) + " 点伤害！";
                if(a[x][w].p <= 0) { onUnitKilled(x, w); v += " AI单位被击破！"; }
            }
        }
    }
    if(v != "AI行动：") h = v;
    else h = "AI结束回合。";
}

void showHelp()
{
    system("cls");
    cout << "==============================================================" << endl;
    cout << "||                    种族大战 - 游戏介绍                  ||" << endl;
    cout << "==============================================================" << endl << endl;
    cout << "【九大种族】" << endl;
    cout << "1. 人类：总部20。被动：每回合第一张部署-1费；手牌上限+1。" << endl;
    cout << "2. 精灵：总部18。被动：弓手+1攻；后方弓手隐匿1回合；近战生命-1。" << endl;
    cout << "3. 矮人：总部24。被动：所有单位部署获1护甲；移动花费+1；免疫恐惧。" << endl;
    cout << "4. 地精：总部14。被动：初始补给+1；击杀+1行动点；所有单位生命-1；手牌上限+2。" << endl;
    cout << "5. 兽人：总部22。被动：单位受伤后攻击+1；战士移动后仍可攻击一次。" << endl;
    cout << "6. 亡灵：总部16。被动：友军死亡50%变1/1骷髅；治疗减半；击杀回1生命。" << endl;
    cout << "7. 血族：总部18。被动：造成伤害回一半生命；总部每回合-1生命；击杀回2生命。" << endl;
    cout << "8. 神族：总部22。被动：开局选分支，每3回合触发一次群体效果。" << endl;
    cout << "9. 克苏鲁：总部15。被动：敌方攻击25%随机目标；每回合给敌方1层疯狂。" << endl << endl;
    cout << "【Buff / Debuff 符号表】" << endl;
    cout << "! | 嘲讽 | 敌方必须优先攻击" << endl;
    cout << "? | 力量 | 打血量低于自己的目标伤害翻倍" << endl;
    cout << "- | 闪电 | 攻击溅射相邻单位半伤" << endl;
    cout << "/ | 穿透 | 目标获虚弱（无法治疗，受到伤害 +50%）" << endl;
    cout << "^ | 暴动 | 目标获恐惧（无法攻击农民）" << endl;
    cout << "+ | 再生 | 回合结束回血" << endl;
    cout << "% | 吸血 | 造成伤害回一半生命" << endl;
    cout << "= | 重甲 | 受到物理/远程伤害 -1，每回合最多 -3" << endl;
    cout << "~ | 灵体 | 物理减半，魔法 +50%" << endl;
    cout << "@ | 狂暴 | 受伤后攻击 +1，最多 +3" << endl;
    cout << "# | 统御 | 周围友军攻击 +1" << endl;
    cout << "$ | 贪婪 | 击杀获 1 行动点" << endl;
    cout << "< | 偷袭 | 攻击前先造成 1 闪电伤害" << endl;
    cout << "> | 精准 | 远程 +1，无视嘲讽" << endl;
    cout << "_ | 隐匿 | 部署当回合不可被选为目标" << endl;
    cout << "* | 恐惧 | 无法攻击农民" << endl;
    cout << "P | 中毒 | 回合结束受伤害" << endl;
    cout << "B | 燃烧 | 回合结束受伤害，怕火 +1" << endl;
    cout << "F | 冻结 | 下回合移动/攻击多花 1 行动点" << endl;
    cout << "D | 眩晕 | 下回合不能行动" << endl;
    cout << "S | 沉默 | 不能使用技能" << endl;
    cout << "M | 疯狂 | 攻击随机选目标" << endl << endl;
    cout << "人类" << endl;
    cout << "A 征兵令：抽 2 张牌" << endl;
    cout << "B 方阵冲锋：目标排获嘲讽" << endl;
    cout << "C 国王税：总部 -2 血换 +3 行动点" << endl;
    cout << "D 战地医院：治疗 3 点并清除负面" << endl;
    cout << "E 战术撤退：前排单位撤回后排并获重甲" << endl;
    cout << "精灵" << endl;
    cout << "A 月华箭：2 点魔法伤害" << endl;
    cout << "B 森林庇护：一排获灵体" << endl;
    cout << "C 精准齐射：一排 2 点远程伤害" << endl;
    cout << "D 藤蔓缠绕：目标眩晕 + 虚弱" << endl;
    cout << "E 风行步：目标获隐匿" << endl;
    cout << "矮人" << endl;
    cout << "A 符文护甲：目标获重甲 2" << endl;
    cout << "B 山岳阵线：一排获嘲讽 + 生命 +1" << endl;
    cout << "C 锻炉爆鸣：3 点火焰伤害" << endl;
    cout << "D 深矿塌方：一排 2 点伤害 + 眩晕" << endl;
    cout << "E 符文铭刻：目标攻击 +1" << endl;
    cout << "地精" << endl;
    cout << "A 炸弹：范围 2 点火焰伤害" << endl;
    cout << "B 抢劫：1 点伤害，击杀获 2 行动点" << endl;
    cout << "C 地精市场：抽 1 张牌" << endl;
    cout << "D 自爆冲锋：单位死亡范围 3 点火焰伤害" << endl;
    cout << "E 混乱烟雾：一排获疯狂" << endl;
    cout << "兽人" << endl;
    cout << "A 战吼：一排获统御" << endl;
    cout << "B 狂怒冲锋：目标攻击 +2" << endl;
    cout << "C 血祭：总部 -2 血换 +3 行动点" << endl;
    cout << "D 先祖之魂：总部回复 4 点" << endl;
    cout << "E 破甲投斧：2 点伤害 + 虚弱" << endl;
    cout << "亡灵" << endl;
    cout << "A 亡者复生：召唤 1/1 骷髅" << endl;
    cout << "B 尸爆：牺牲单位范围伤害" << endl;
    cout << "C 灵魂虹吸：2 点伤害 + 回复 2 点" << endl;
    cout << "D 墓园之门：召唤 2 个骷髅" << endl;
    cout << "E 瘟疫云：一排中毒 2 层 + 虚弱" << endl;
    cout << "血族" << endl;
    cout << "A 血祭：总部 -2 血换 +3 行动点" << endl;
    cout << "B 血月：全体血族攻击 +1 + 吸血" << endl;
    cout << "C 鲜血契约：目标获吸血 + 血怒" << endl;
    cout << "D 暗夜突袭：目标获隐匿" << endl;
    cout << "E 吸血箭：2 点伤害 + 回复 1 点" << endl;
    cout << "神族" << endl;
    cout << "A 神谕：抽 1 张牌" << endl;
    cout << "B 圣光普照：全体治疗 2 点" << endl;
    cout << "C 日月同辉：全体获分支效果" << endl;
    cout << "D 元素风暴：一排火焰 + 冰霜 + 闪电" << endl;
    cout << "E 圣盾术：目标获重甲 1" << endl;
    cout << "克苏鲁" << endl;
    cout << "A 深渊召唤：召唤 2/2 触手" << endl;
    cout << "B 疯狂低语：目标获疯狂" << endl;
    cout << "C 不可名状：一排恐惧 + 虚弱" << endl;
    cout << "D 星之眷族：召唤 4-6 眷族" << endl;
    cout << "E 污染蔓延：目标中毒 1 层" << endl;
    cout << "==============================================================" << endl;
    cout << "输入任意键返回战场..." << endl;
    string temp;
    getline(cin, temp);
}

void gg()
{
    system("cls");
    cout << "==============================" << endl;
    cout << "||         种族大战         ||" << endl;
    cout << "==============================" << endl << endl;
    cout << "  请选择游戏模式：" << endl;
    cout << "  1. 双人对弈" << endl;
    cout << "  2. 人机对弈 - 简单" << endl;
    cout << "  3. 人机对弈 - 普通" << endl;
    cout << "  4. 人机对弈 - 困难" << endl << endl;
    cout << "  输入数字选择 (1-4): ";
    int v;
    cin >> v;
    cin.ignore(10000, '\n');
    if(v == 1) { i = 0; j = 0; }
    else if(v == 2) { i = 1; j = 0; }
    else if(v == 3) { i = 2; j = 1; }
    else if(v == 4) { i = 3; j = 2; }
    else { i = 1; j = 0; }

    system("cls");
    cout << "==============================" << endl;
    cout << "||         种族大战         ||" << endl;
    cout << "==============================" << endl << endl;
    cout << "  请选择你的种族：" << endl;
    cout << "  1. 人类   2. 精灵   3. 矮人   4. 地精   5. 兽人" << endl;
    cout << "  6. 亡灵   7. 血族   8. 神族   9. 克苏鲁  0. 随机" << endl;
    cout << "  输入数字选择 (0-9): ";
    int v1;
    cin >> v1;
    cin.ignore(10000, '\n');
    if(v1 >= 1 && v1 <= 9) racePlayer = v1;
    else racePlayer = 1 + rng() % 9;
    if(racePlayer == 8)
    {
        system("cls");
        cout << "  神族分支选择：" << endl;
        cout << "  1. 天使   2. 日族   3. 月族   4. 自然元素" << endl;
        cout << "  输入数字选择 (1-4): ";
        int b1;
        cin >> b1;
        cin.ignore(10000, '\n');
        if(b1 >= 1 && b1 <= 4) playerRaceBranch = b1;
        else playerRaceBranch = 1;
    }
    if(i == 0)
    {
        system("cls");
        cout << "==============================" << endl;
        cout << "||         种族大战         ||" << endl;
        cout << "==============================" << endl << endl;
        cout << "  请为玩家2选择种族：" << endl;
        cout << "  1. 人类   2. 精灵   3. 矮人   4. 地精   5. 兽人" << endl;
        cout << "  6. 亡灵   7. 血族   8. 神族   9. 克苏鲁  0. 随机" << endl;
        cout << "  输入数字选择 (0-9): ";
        int v2;
        cin >> v2;
        cin.ignore(10000, '\n');
        if(v2 >= 1 && v2 <= 9) raceAI = v2;
        else raceAI = 1 + rng() % 9;
        if(raceAI == 8)
        {
            system("cls");
            cout << "  玩家2神族分支选择：" << endl;
            cout << "  1. 天使   2. 日族   3. 月族   4. 自然元素" << endl;
            cout << "  输入数字选择 (1-4): ";
            int b2;
            cin >> b2;
            cin.ignore(10000, '\n');
            if(b2 >= 1 && b2 <= 4) aiRaceBranch = b2;
            else aiRaceBranch = 1;
        }
    }
    else
    {
        system("cls");
        cout << "==============================" << endl;
        cout << "||         种族大战         ||" << endl;
        cout << "==============================" << endl << endl;
        cout << "  请为 AI 选择种族：" << endl;
        cout << "  1. 人类   2. 精灵   3. 矮人   4. 地精   5. 兽人" << endl;
        cout << "  6. 亡灵   7. 血族   8. 神族   9. 克苏鲁  0. 随机" << endl;
        cout << "  输入数字选择 (0-9): ";
        int v2;
        cin >> v2;
        cin.ignore(10000, '\n');
        if(v2 >= 1 && v2 <= 9) raceAI = v2;
        else raceAI = 1 + rng() % 9;
        if(raceAI == 8) aiRaceBranch = 1 + rng() % 4;
    }

    switch(racePlayer)
    {
        case 1: hqPlayerMax = 20; break;
        case 2: hqPlayerMax = 18; break;
        case 3: hqPlayerMax = 24; break;
        case 4: hqPlayerMax = 14; break;
        case 5: hqPlayerMax = 22; break;
        case 6: hqPlayerMax = 16; break;
        case 7: hqPlayerMax = 18; break;
        case 8: hqPlayerMax = 22; break;
        case 9: hqPlayerMax = 15; break;
        default: hqPlayerMax = 20; break;
    }
    switch(raceAI)
    {
        case 1: hqAIMax = 20; break;
        case 2: hqAIMax = 18; break;
        case 3: hqAIMax = 24; break;
        case 4: hqAIMax = 14; break;
        case 5: hqAIMax = 22; break;
        case 6: hqAIMax = 16; break;
        case 7: hqAIMax = 18; break;
        case 8: hqAIMax = 22; break;
        case 9: hqAIMax = 15; break;
        default: hqAIMax = 20; break;
    }

    cout << "你选择了种族 " << racePlayer << "，对手种族 " << raceAI << "。" << endl;
    cout << "按回车继续..." << endl;
    string tmp;
    getline(cin, tmp);
}

int main()
{
    while(true)
    {
        gg();
        gc();
        bool gameOver = false;
        while(!gameOver)
        {
            activePlayer = (i == 0) ? turnSide : 1;
            system("cls");
            gb();
            if(a[0][2].p <= 0 || a[2][2].p <= 0)
            {
                gameOver = true;
                break;
            }
            cout << "你的指令 > ";
            string v;
            getline(cin, v);
            if(v.empty()) continue;
            if(v == "quit" || v == "QUIT" || v == "Quit" || v == " q" || v == " Q")
            {
                cout << "游戏退出，感谢游玩！" << endl;
                return 0;
            }
            if(v == "?")
            {
                showHelp();
                continue;
            }
            if(v == "f" || v == "F")
            {
                int mySide = activePlayer;

                int u = 0;
                for(int r = 0; r < cc; ++r)
                    for(int x = 0; x < dd; ++x)
                        if(!a[r][x].r && a[r][x].q == 'f' && a[r][x].v == mySide) u++;

                if(i == 0)
                {
                    if(mySide == 1) { e += (1 + u); d = e; }
                    else { g += (1 + u); f = g; }
                    int t = 5 + u;
                    if(mySide == 1 && racePlayer == 1) t += 1;
                    if(mySide == 1 && racePlayer == 4) t += 2;
                    if(mySide == 2 && raceAI == 1) t += 1;
                    if(mySide == 2 && raceAI == 4) t += 2;
                    if((int)b.size() < t)
                    {
                        if(rng() % 100 < 30) b.push_back(fh_action(mySide - 1));
                        else b.push_back(fh(e, (mySide == 1) ? 0 : 2));
                    }
                    fi();
                    k++;
                    if(mySide == 1) firstDeployUsed = false;
                    else aiFirstDeployUsed = false;
                    resolveStatus();
                    if(mySide == 1 && racePlayer == 9)
                    {
                        for(int r = 0; r < 2; ++r)
                            for(int c2 = 0; c2 < dd; ++c2)
                                if(!a[r][c2].r && a[r][c2].v == 2)
                                {
                                    mad[r][c2] = 1;
                                    addBuffToCard(r, c2, 'M');
                                }
                    }
                    if(mySide == 2 && raceAI == 9)
                    {
                        for(int r = 1; r < cc; ++r)
                            for(int c2 = 0; c2 < dd; ++c2)
                                if(!a[r][c2].r && a[r][c2].v == 1)
                                {
                                    mad[r][c2] = 1;
                                    addBuffToCard(r, c2, 'M');
                                }
                    }
                    turnCount++;
                    if(mySide == 1 && racePlayer == 7) a[2][2].p -= 1;
                    if(mySide == 2 && raceAI == 7) a[0][2].p -= 1;
                    if(turnCount % 3 == 0)
                    {
                        if(mySide == 1 && racePlayer == 8)
                        {
                            for(int r = 1; r < cc; ++r)
                                for(int c2 = 0; c2 < dd; ++c2)
                                    if(!a[r][c2].r && a[r][c2].q != 'H' && a[r][c2].v == 1)
                                    {
                                        if(playerRaceBranch == 1) a[r][c2].p += 1;
                                        else if(playerRaceBranch == 2) a[r][c2].o += 1;
                                        else if(playerRaceBranch == 3) { a[r][c2].p += 1; a[r][c2].s = true; }
                                        else if(playerRaceBranch == 4) { a[r][c2].p += 1; a[r][c2].o += 1; }
                                    }
                        }
                        if(mySide == 2 && raceAI == 8)
                        {
                            for(int r = 0; r < 2; ++r)
                                for(int c2 = 0; c2 < dd; ++c2)
                                    if(!a[r][c2].r && a[r][c2].q != 'H' && a[r][c2].v == 2)
                                    {
                                        if(aiRaceBranch == 1) a[r][c2].p += 1;
                                        else if(aiRaceBranch == 2) a[r][c2].o += 1;
                                        else if(aiRaceBranch == 3) { a[r][c2].p += 1; a[r][c2].s = true; }
                                        else if(aiRaceBranch == 4) { a[r][c2].p += 1; a[r][c2].o += 1; }
                                    }
                        }
                    }
                    for(int r = 0; r < cc; ++r)
                        for(int c2 = 0; c2 < dd; ++c2)
                            if(!a[r][c2].r && a[r][c2].v == mySide)
                            {
                                frozen[r][c2] = 0;
                                stunned[r][c2] = 0;
                                silent[r][c2] = 0;
                                mad[r][c2] = 0;
                                bleeding[r][c2] = 0;
                                firstStrike[r][c2] = 0;
                                hidden[r][c2] = 0;
                                taunt[r][c2] = 0;
                                power[r][c2] = 0;
                                lightning[r][c2] = 0;
                                pierce[r][c2] = 0;
                                riot[r][c2] = 0;
                                rage[r][c2] = 0;
                                command[r][c2] = 0;
                                greedy[r][c2] = 0;
                                precise[r][c2] = 0;
                                armor[r][c2] = 0;
                                spirit[r][c2] = 0;
                            }
                    swap(b, c);
                    swap(d, f);
                    swap(e, g);
                    if(turnSide == 1) turnSide = 2;
                    else turnSide = 1;
                    activePlayer = turnSide;
                    h = "玩家" + to_string(turnSide) + "回合开始。";
                }
                else
                {
                    e += (1 + u);
                    d = e;
                    int aiFarmers = 0;
                    for(int r = 0; r < cc; ++r)
                        for(int c2 = 0; c2 < dd; ++c2)
                            if(!a[r][c2].r && a[r][c2].v == 2 && a[r][c2].q == 'f') aiFarmers++;
                    g += 1 + aiFarmers;
                    f = g;
                    int t = 5 + u;
                    if(racePlayer == 1) t += 1;
                    if(racePlayer == 4) t += 2;
                    if((int)b.size() < t)
                    {
                        if(rng() % 100 < 30) b.push_back(fh_action(0));
                        else b.push_back(fh(e, 0));
                    }
                    firstDeployUsed = false;
                    resolveStatus();
                    if(racePlayer == 9)
                    {
                        for(int r = 0; r < 2; ++r)
                            for(int c2 = 0; c2 < dd; ++c2)
                                if(!a[r][c2].r && a[r][c2].v == 2)
                                {
                                    mad[r][c2] = 1;
                                    addBuffToCard(r, c2, 'M');
                                }
                    }
                    turnCount++;
                    if(racePlayer == 7) a[2][2].p -= 1;
                    if(raceAI == 7) a[0][2].p -= 1;
                    if(turnCount % 3 == 0)
                    {
                        if(racePlayer == 8)
                        {
                            for(int r = 1; r < cc; ++r)
                                for(int c2 = 0; c2 < dd; ++c2)
                                    if(!a[r][c2].r && a[r][c2].q != 'H' && a[r][c2].v == 1)
                                    {
                                        if(playerRaceBranch == 1) a[r][c2].p += 1;
                                        else if(playerRaceBranch == 2) a[r][c2].o += 1;
                                        else if(playerRaceBranch == 3) { a[r][c2].p += 1; a[r][c2].s = true; }
                                        else if(playerRaceBranch == 4) { a[r][c2].p += 1; a[r][c2].o += 1; }
                                    }
                        }
                    }
                    for(int r = 0; r < cc; ++r)
                        for(int c2 = 0; c2 < dd; ++c2)
                            if(!a[r][c2].r && a[r][c2].v == 1)
                            {
                                frozen[r][c2] = 0;
                                stunned[r][c2] = 0;
                                silent[r][c2] = 0;
                                mad[r][c2] = 0;
                                bleeding[r][c2] = 0;
                                firstStrike[r][c2] = 0;
                                hidden[r][c2] = 0;
                                taunt[r][c2] = 0;
                                power[r][c2] = 0;
                                lightning[r][c2] = 0;
                                pierce[r][c2] = 0;
                                riot[r][c2] = 0;
                                rage[r][c2] = 0;
                                command[r][c2] = 0;
                                greedy[r][c2] = 0;
                                precise[r][c2] = 0;
                                armor[r][c2] = 0;
                                spirit[r][c2] = 0;
                            }
                    gf();
                    for(int r = 0; r < cc; ++r)
                        for(int c2 = 0; c2 < dd; ++c2)
                            if(!a[r][c2].r && a[r][c2].v == 2)
                            {
                                frozen[r][c2] = 0;
                                stunned[r][c2] = 0;
                                silent[r][c2] = 0;
                                mad[r][c2] = 0;
                                bleeding[r][c2] = 0;
                                firstStrike[r][c2] = 0;
                                hidden[r][c2] = 0;
                                taunt[r][c2] = 0;
                                power[r][c2] = 0;
                                lightning[r][c2] = 0;
                                pierce[r][c2] = 0;
                                riot[r][c2] = 0;
                                rage[r][c2] = 0;
                                command[r][c2] = 0;
                                greedy[r][c2] = 0;
                                precise[r][c2] = 0;
                                armor[r][c2] = 0;
                                spirit[r][c2] = 0;
                            }
                    fi();
                    k++;
                    aiFirstDeployUsed = false;
                    if(raceAI == 9)
                    {
                        for(int r = 1; r < cc; ++r)
                            for(int c2 = 0; c2 < dd; ++c2)
                                if(!a[r][c2].r && a[r][c2].v == 1)
                                {
                                    mad[r][c2] = 1;
                                    addBuffToCard(r, c2, 'M');
                                }
                    }
                    if(u > 0) h += " 农民为你额外提供了 " + to_string(u) + " 点补给！";
                }
                continue;
            }
            stringstream ss(v);
            string s1, s2, s3, s4, s5;
            ss >> s1 >> s2 >> s3 >> s4 >> s5;
            if(s1.size() != 1 || (s1[0] != 'q' && s1[0] != 'w' && s1[0] != 'e' && s1[0] != 'r' &&
                                   s1[0] != 'Q' && s1[0] != 'W' && s1[0] != 'E' && s1[0] != 'R'))
            {
                h = "错误：源区域无效！请使用 q/w/e/r。";
                continue;
            }
            char w = fa(s1[0]);
            int x = 0;
            try { x = stoi(s2); }
            catch(...) { h = "错误：源序号必须是数字！"; continue; }
            if(s3 == "a" || s3 == "A")
            {
                if(s4.empty() || s5.empty()) { h = "错误：攻击指令不完整！"; continue; }
                if(s4.size() != 1 || (s4[0] != 'q' && s4[0] != 'w' && s4[0] != 'e' && s4[0] != 'r' &&
                                       s4[0] != 'Q' && s4[0] != 'W' && s4[0] != 'E' && s4[0] != 'R'))
                {
                    h = "错误：目标区域无效！";
                    continue;
                }
                char y = fa(s4[0]);
                int z = 0;
                try { z = stoi(s5); }
                catch(...) { h = "错误：目标序号必须是数字！"; continue; }
                ge(w, x, y, z);
            }
            else if(s3 == "u" || s3 == "U")
            {
                if(x < 1 || x > (int)b.size()) { h = "错误：手牌序号无效！"; continue; }
                A& card = b[x - 1];
                if(card.q < 'A' || card.q > 'I') { h = "错误：该手牌不是行动卡！"; continue; }
                int cost = card.m;
                if(d < cost) { h = "错误：行动点不足！"; continue; }
                char tz = ' ';
                int ti = 0;
                if(!s4.empty() && !s5.empty())
                {
                    tz = fa(s4[0]);
                    try { ti = stoi(s5); } catch(...) { ti = 0; }
                }
                else if(!s4.empty()) tz = fa(s4[0]);
                int cid = card.q - 'A';
                d -= cost;
                b.erase(b.begin() + x - 1);
                useActionCard(cid, tz, ti, activePlayer);
            }
            else
            {
                if(s3.empty() || s4.empty()) { h = "错误：移动指令不完整！"; continue; }
                if(s3.size() != 1 || (s3[0] != 'q' && s3[0] != 'w' && s3[0] != 'e' && s3[0] != 'r' &&
                                       s3[0] != 'Q' && s3[0] != 'W' && s3[0] != 'E' && s3[0] != 'R'))
                {
                    h = "错误：目标区域无效！";
                    continue;
                }
                char y = fa(s3[0]);
                int z = 0;
                try { z = stoi(s4); }
                catch(...) { h = "错误：目标序号必须是数字！"; continue; }
                gd(w, x, y, z);
            }
        }
        bool win = (a[0][2].p <= 0);
        while(true)
        {
            system("cls");
            aa(win ? 10 : 12);
            cout << "==============================" << endl;
            cout << "||         游戏结束         ||" << endl;
            cout << "==============================" << endl << endl;
            if(win) cout << "  恭喜！敌方总部已被摧毁，你获得了胜利！" << endl << endl;
            else cout << "  很遗憾，你的总部已被摧毁，游戏结束。" << endl << endl;
            bb();
            cout << "  1. 返回主界面再来一局" << endl;
            cout << "  2. 退出游戏" << endl;
            cout << "  请选择 (1-2): ";
            string choice;
            getline(cin, choice);
            if(choice == "1") break;
            else if(choice == "2") { cout << "游戏退出，感谢游玩！" << endl; return 0; }
        }
    }
    return 0;
}
