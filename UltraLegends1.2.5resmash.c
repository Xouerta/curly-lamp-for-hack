#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// 游戏状态结构体
typedef struct {
    int hp_max, hp_cur;
    int mp_max, mp_cur;
    int atk, skill;
    int gold, core;
    int criminal;
    int job;
} Player;

typedef struct {
    char name[30];
    int hp;
    int atk;
    int is_boss;
} Enemy;

// 职业配置
const struct {
    int hp_delta;
    int atk_delta;
    int mp_delta;
    int skill_delta;
    int gold_delta;
    char name[10];
    char skill_name[15];
} JOBS[] = {
    {0, 0, 0, 0, 0, "战士", "十字斩"},
    {-200, 10, 0, 10, 0, "刺客", "暗影突袭"},
    {-250, 40, 0, 20, 0, "剑豪", "万剑之战"},
    {-300, -20, 100, 0, 0, "法师", "魔法光波"},
    {-200, -10, -50, -50, 500, "富二代", "金钱万能"}
};

// 商店物品
typedef struct {
    char name[20];
    int cost;
    int hp_bonus;
    int atk_bonus;
    int mp_bonus;
    int skill_bonus;
} ShopItem;

const ShopItem WEAPON_SHOP[] = {
    {"铁剑", 200, 0, 20, 0, 0},
    {"银剑", 300, 0, 40, 0, 0},
    {"金盾", 200, 300, 0, 0, 0},
    {"圣盾", 500, 500, 0, 0, 100},
    {"誓约剑", 2000, 0, 200, 0, 0},
    {"日耀剑", 3000, 0, 400, 0, 0},
    {"抛光银盾", 2500, 1000, 0, 0, 0},
    {"龙鳞甲", 5000, 5000, 0, 0, 300}
};

// 抽卡奖励
typedef struct {
    char name[50];
    int hp_bonus;
    int atk_bonus;
    int rate;  // 概率权重
} GachaItem;

const GachaItem GACHA_POOL[] = {
    {"★☆★☆★ 雉草之道光 ★☆★☆★", 300, 100, 7},
    {"★☆★☆★ 火焰之剑 ★☆★☆★", 150, 70, 19},
    {"★☆★☆★ 冰霜之剑 ★☆★☆★", 150, 70, 19},
    {"★☆★☆★ 涂毒匕首 ★☆★☆★", 150, 70, 19},
    {"★☆★☆★ 屠龙剑 ★☆★☆★", 150, 70, 19},
    {"★☆★☆★ 粉碎者战锤 ★☆★☆★", 150, 70, 19},
    {"★☆★☆★ 撕裂者战斧 ★☆★☆★", 150, 70, 19},
    {"★☆★☆ 安德门徒权杖 ★☆★☆", 50, 30, 50},
    {"★☆★☆ 魔法竖琴 ★☆★☆", 50, 30, 50},
    {"★☆★☆ 食人魔战锤 ★☆★☆", 50, 30, 50},
    {"★☆★☆ 复仇之刃 ★☆★☆", 50, 30, 50},
    {"★☆ 精良战斧 ★☆", 30, 10, 100},
    {"★☆ 普通长剑 ★☆", 20, 5, 200}
};

// 函数声明
void print_title();
void print_story();
int select_job(Player *p);
int select_gift(Player *p);
void state(Player p);
void combat(Player *p, Enemy e, int act);
void shop(Player *p, int shop_type);
void inn(Player *p, int act);
void train(Player *p);
void temple(Player *p);
void hospital(Player *p, int cost);
void casino(Player *p);
void gacha(Player *p, int act);
void apply_item(Player *p, const ShopItem *item);
void heal(Player *p, int hp_heal, int mp_heal);
void add_gold(Player *p, int amount);
bool check_gold(Player *p, int amount);
void add_stats(Player *p, int hp, int atk, int mp, int skill);

// 工具函数
void add_stats(Player *p, int hp, int atk, int mp, int skill) {
    p->hp_max += hp;
    p->hp_cur += hp;
    p->atk += atk;
    p->mp_max += mp;
    p->mp_cur += mp;
    p->skill += skill;
}

void state(Player p) {
    printf("你的属性：HP：%d/%d，MP %d/%d，攻击力 %d，金币 %d，许愿之源 %d", 
           p.hp_cur, p.hp_max, p.mp_cur, p.mp_max, p.atk, p.gold, p.core);
}

void heal(Player *p, int hp_heal, int mp_heal) {
    p->hp_cur = (p->hp_cur + hp_heal > p->hp_max) ? p->hp_max : p->hp_cur + hp_heal;
    p->mp_cur = (p->mp_cur + mp_heal > p->mp_max) ? p->mp_max : p->mp_cur + mp_heal;
}

bool check_gold(Player *p, int amount) {
    if (p->gold < amount) {
        printf("金币不足！需要 %d 金币\n", amount);
        return false;
    }
    return true;
}

void add_gold(Player *p, int amount) {
    p->gold += amount;
    printf("获得 %d 金币！\n", amount);
}

// 战斗系统
void combat(Player *p, Enemy e, int act) {
    int enemy_hp = e.hp;
    int enemy_atk = e.atk;
    char *skill_name = JOBS[p->job].skill_name;
    int mp_cost = (act == 2) ? 100 : 50;
    
    printf("\n你遇到了%s！生命值：%d\n", e.name, enemy_hp);
    
    while (enemy_hp > 0 && p->hp_cur > 0) {
        printf("\n轮到你行动了！\n1.普通攻击 2.%s 3.休息 4.判断战局\n", skill_name);
        
        int action;
        scanf("%d", &action);
        
        switch (action) {
            case 1:
                enemy_hp -= p->atk;
                printf("你对%s使用普通攻击！造成%d点伤害！还剩%d点生命！\n", 
                       e.name, p->atk, enemy_hp > 0 ? enemy_hp : 0);
                break;
                
            case 2:
                if (p->mp_cur >= mp_cost) {
                    enemy_hp -= p->skill;
                    p->mp_cur -= mp_cost;
                    printf("你对%s使用%s！造成%d点伤害！还剩%d点生命！剩余MP：%d\n", 
                           e.name, skill_name, p->skill, enemy_hp > 0 ? enemy_hp : 0, p->mp_cur);
                } else {
                    printf("MP不足！\n");
                    continue;
                }
                break;
                
            case 3:
                heal(p, 50, 50);
                printf("你休息一会，恢复50HP和50MP！\n");
                break;
                
            case 4:
                state(*p);
                printf("\n%s还剩%d点生命\n", e.name, enemy_hp);
                continue;
        }
        
        if (enemy_hp <= 0) {
            printf("\n你击败了%s！\n", e.name);
            break;
        }
        
        p->hp_cur -= enemy_atk;
        printf("%s对你造成%d点伤害！你还剩%d点生命！\n", e.name, enemy_atk, p->hp_cur);
    }
    
    if (p->hp_cur <= 0) {
        printf("\n你被击败了！游戏结束！\n");
        exit(0);
    }
}

// 抽卡系统
void gacha(Player *p, int act) {
    printf("\n✨ 许愿池 ✨\n");
    printf("池水清澈，散发着金色光芒...\n");
    printf("1.单抽一次 (1个许愿之源)\n2.十连抽 (10个许愿之源)\n3.离开\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 3) return;
    
    int cost = (choice == 1) ? 1 : 10;
    if (p->core < cost) {
        printf("许愿之源不足！去做任务获得吧！\n");
        return;
    }
    
    printf("\n✨ 你投入了许愿之源，池水发出耀眼的光芒... ✨\n\n");
    p->core -= cost;
    
    int pulls = (choice == 1) ? 1 : 10;
    for (int i = 0; i < pulls; i++) {
        int r = rand() % 1000;
        const GachaItem *selected = NULL;
        
        if (r < 70) { // 7% SSR
            selected = &GACHA_POOL[0];
        } else if (r < 260) { // 19% SR
            int idx = 1 + rand() % 5; // 第1-5个是SR
            selected = &GACHA_POOL[idx];
        } else if (r < 760) { // 50% R
            int idx = 6 + rand() % 5; // 第6-10个是R
            selected = &GACHA_POOL[idx];
        } else { // 24% N
            int idx = 11 + rand() % 2; // 第11-12个是N
            selected = &GACHA_POOL[idx];
        }
        
        printf("获得：%s\n", selected->name);
        add_stats(p, selected->hp_bonus, selected->atk_bonus, 0, 0);
    }
    
    if (pulls == 10) {
        printf("\n✨ 十连抽额外奖励：许愿之源+1 ✨\n");
        p->core += 1;
    }
}

// 商店系统
void shop(Player *p, int shop_type) {
    int start = (shop_type == 0) ? 0 : 4;
    int end = (shop_type == 0) ? 4 : 8;
    
    printf("\n欢迎光临！想要点什么？\n");
    for (int i = start; i < end; i++) {
        printf("%d.%s - %dg ", i - start + 1, WEAPON_SHOP[i].name, WEAPON_SHOP[i].cost);
    }
    printf("5.离开\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice >= 1 && choice <= 4) {
        int idx = start + choice - 1;
        if (check_gold(p, WEAPON_SHOP[idx].cost)) {
            p->gold -= WEAPON_SHOP[idx].cost;
            add_stats(p, WEAPON_SHOP[idx].hp_bonus, WEAPON_SHOP[idx].atk_bonus, 
                     WEAPON_SHOP[idx].mp_bonus, WEAPON_SHOP[idx].skill_bonus);
            printf("你购买了%s！属性提升！\n", WEAPON_SHOP[idx].name);
        }
    } else if (choice == 5 && shop_type == 0) {
        printf("你敢打劫？\n");
        Enemy boss = {"愤怒的老板", 800, 100, 0};
        combat(p, boss, 1);
        if (p->hp_cur > 0) {
            add_gold(p, 900);
            add_stats(p, 900, 90, 0, 0);
            p->criminal = 1;
        }
    }
}

// 旅店系统
void inn(Player *p, int act) {
    printf("\n在旅店里...\n");
    printf("1.小童仆 2.神秘人 3.老板 4.老板女儿 5.可疑的人 6.赏金警官\n");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("%s\n", act == 1 ? "小童仆分享他的梦想..." : "小童仆向你下跪：国王陛下！");
            break;
        case 2:
            if (act == 1) {
                printf("神秘人：帮我买瓶酒...\n");
                add_gold(p, 4);
                printf("你获得4金币！攻击力+5！\n");
                p->atk += 5;
            } else {
                printf("神秘人：屠龙者终将成龙...\n");
            }
            break;
        case 5:
            printf("一个可疑的人...\n");
            if (act == 1) {
                printf("他给你一把黑曜石匕首！攻击力+5！\n");
                p->atk += 5;
            }
            break;
        case 6:
            printf("%s\n", act == 1 ? "警官：去清理山贼吧！" : "市长：请肃清江洋大盗！");
            if (act == 1) {
                Enemy bandit = {"山贼", 400, 20, 0};
                combat(p, bandit, 1);
                if (p->hp_cur > 0) {
                    add_gold(p, 100);
                    p->core += 1;
                    printf("获得许愿之源+1！\n");
                }
            } else {
                Enemy thief = {"江洋大盗", 2000, 80, 0};
                combat(p, thief, 2);
                if (p->hp_cur > 0) {
                    add_gold(p, 1000);
                    p->core += 2;
                    printf("获得许愿之源+2！\n");
                }
            }
            break;
    }
}

// 训练馆
void train(Player *p) {
    const struct {
        char name[10];
        int cost;
        int hp;
        int atk;
        int mp;
        int skill;
    } TRAIN[] = {
        {"圣骑士", 70, 20, 0, 0, 50},
        {"狂战士", 100, 50, 20, 0, 0},
        {"法师", 50, 0, 0, 50, 0}
    };
    
    printf("\n选择训练师：\n");
    for (int i = 0; i < 3; i++) {
        printf("%d.%s - %dg ", i+1, TRAIN[i].name, TRAIN[i].cost);
    }
    printf("4.离开\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice >= 1 && choice <= 3 && check_gold(p, TRAIN[choice-1].cost)) {
        p->gold -= TRAIN[choice-1].cost;
        add_stats(p, TRAIN[choice-1].hp, TRAIN[choice-1].atk, 
                 TRAIN[choice-1].mp, TRAIN[choice-1].skill);
        printf("训练完成！属性提升！\n");
    }
}

// 神殿
void temple(Player *p) {
    if (p->criminal) {
        printf("你的罪行触怒了众神！\n");
        return;
    }
    
    printf("\n在神殿中...\n");
    printf("1.供奉神像 2.捐款 3.离开\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        const struct {
            char name[10];
            int cost;
            int hp;
            int atk;
            int mp;
            int skill;
        } GODS[] = {
            {"奥古斯丁", 350, 200, 0, 0, 150},
            {"索尔", 500, 300, 150, 0, 0},
            {"梅林", 250, 0, 0, 150, 0}
        };
        
        printf("供奉哪座神像？\n");
        for (int i = 0; i < 3; i++) {
            printf("%d.%s - %dg ", i+1, GODS[i].name, GODS[i].cost);
        }
        printf("4.离开\n");
        
        int god;
        scanf("%d", &god);
        
        if (god >= 1 && god <= 3) {
            if (p->gold >= GODS[god-1].cost) {
                p->gold -= GODS[god-1].cost;
                add_stats(p, GODS[god-1].hp, GODS[god-1].atk, 
                         GODS[god-1].mp, GODS[god-1].skill);
                printf("你获得神明的祝福！\n");
            } else {
                printf("金币不足，触怒了神明！\n");
                if (god == 1) p->atk -= 10;
                else if (god == 2) p->hp_cur -= 100;
                else p->skill -= 10;
            }
        }
    } else if (choice == 2) {
        printf("捐款金额：");
        int donate;
        scanf("%d", &donate);
        
        if (donate > p->gold) donate = p->gold;
        p->gold -= donate;
        
        if (donate >= 1000) {
            add_stats(p, 500, 500, 100, 0);
            printf("慷慨的捐款！获得强大祝福！\n");
        } else if (donate >= 500) {
            add_stats(p, 200, 300, 0, 0);
            printf("获得祝福！\n");
        } else if (donate > 100) {
            add_stats(p, 150, 0, 0, 0);
            printf("获得微小祝福！\n");
        } else {
            printf("小气鬼！\n");
        }
    }
}

// 医院
void hospital(Player *p, int cost) {
    printf("\n医院 - %d金币治疗\n1.治疗 2.离开\n", cost);
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1 && check_gold(p, cost)) {
        p->gold -= cost;
        p->hp_cur = p->hp_max;
        p->mp_cur = p->mp_max;
        printf("完全恢复！\n");
    }
}

// 赌场
void casino(Player *p) {
    printf("\n猜数字游戏！下注金额：");
    
    int bet;
    scanf("%d", &bet);
    
    if (bet > p->gold) {
        printf("金币不足！\n");
        return;
    }
    
    p->gold -= bet;
    int target = rand() % 100 + 1;
    int guess, attempts = 0;
    
    do {
        printf("猜数字(1-100)：");
        scanf("%d", &guess);
        attempts++;
        
        if (guess > target) printf("猜大了！\n");
        else if (guess < target) printf("猜小了！\n");
    } while (guess != target);
    
    printf("猜了%d次\n", attempts);
    
    float multi;
    switch (attempts) {
        case 1: multi = 5.0; printf("天命之子！\n"); break;
        case 2: multi = 3.0; printf("运气爆棚！\n"); break;
        case 3: multi = 2.5; printf("不错！\n"); break;
        case 4: multi = 1.5; printf("运气稍好！\n"); break;
        case 5: multi = 1.25; printf("正常水平！\n"); break;
        default: multi = 0; printf("你输了！\n"); break;
    }
    
    if (multi > 0) {
        p->gold += (int)(bet * multi);
    } else if (p->gold < 0) {
        p->gold = 0;
        p->hp_cur -= 50;
        printf("欠债被暴打！\n");
    }
}

// 游戏主循环
void game_loop(Player *p, int act) {
    int choice;
    
    do {
        printf("\n\n你现在在%s。\n", act == 1 ? "王国首都" : "世界之巅");
        state(*p);
        printf("\n你可以去：\n");
        printf("1.%s 2.武器铺 3.旅店 4.%s 5.医院 6.赌场 7.许愿池\n", 
               act == 1 ? "恶龙城堡" : "世界之巅",
               act == 1 ? "练武馆" : "神殿");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: return;  // 离开去战斗
            case 2: shop(p, act == 2 ? 1 : 0); break;
            case 3: inn(p, act); break;
            case 4: act == 1 ? train(p) : temple(p); break;
            case 5: hospital(p, act == 1 ? 50 : 150); break;
            case 6: casino(p); break;
            case 7: gacha(p, act); break;
        }
    } while (choice != 1);
}

int main() {
    srand((unsigned)time(NULL));
    
    print_title();
    print_story();
    
    Player player = {500, 500, 100, 100, 60, 150, 500, 0, 0, 0};
    
    // 选择职业
    player.job = select_job(&player);
    
    // 选择礼物
    select_gift(&player);
    
    // 第一幕
    game_loop(&player, 1);
    
    // 恶龙之战
    Enemy dragon = {"恶龙", 2500, 50 + rand() % 51, 1};
    printf("\n你来到了恶龙城堡！\n");
    combat(&player, dragon, 1);
    
    if (player.hp_cur > 0) {
        printf("\n你击败了恶龙！获得龙鳞诅咒...\n");
        add_stats(&player, 500, 0, 0, 0);
        add_gold(&player, 5000);
        
        // 第二幕
        game_loop(&player, 2);
        
        // 圣龙之战
        Enemy holy_dragon = {"圣龙", 20000, 50 + rand() % 521, 1};
        printf("\n你来到了世界之巅！\n");
        combat(&player, holy_dragon, 2);
        
        printf("\n你击败了圣龙！\n");
        printf("游戏结束！感谢游玩！\n");
    }
    
    return 0;
}

void print_title() {
    printf("   ===============================================================\n");
    printf("   =                                                             =\n");
    printf("   =                   Ultra       legends      V0.1.3.2        =\n");
    printf("   =                                                             =\n");
    printf("   =                       老张stdio presents                    =\n");
    printf("   =                                                             =\n");
    printf("   ===============================================================\n\n");
}

void print_story() {
    printf("剧情介绍：\n从前，Ultra大陆有一个美丽的王国...\n");
    printf("直到有一天，一头恶龙来到了首都的西部荒野...\n");
    printf("你作为最强大的勇士，准备前往城堡救出公主...\n\n");
}

int select_job(Player *p) {
    printf("请选择职业：\n");
    for (int i = 0; i < 5; i++) {
        printf("%d.%s ", i + 1, JOBS[i].name);
    }
    printf("\n");
    
    int choice;
    scanf("%d", &choice);
    choice--;
    
    if (choice >= 0 && choice < 5) {
        add_stats(p, JOBS[choice].hp_delta, JOBS[choice].atk_delta, 
                 JOBS[choice].mp_delta, JOBS[choice].skill_delta);
        p->gold += JOBS[choice].gold_delta;
        p->job = choice;
    } else {
        printf("输入错误！默认选择战士\n");
        p->job = 0;
    }
    
    return p->job;
}

int select_gift(Player *p) {
    printf("\n选择一个出生礼物：\n");
    printf("1.额外金币 2.小刀 3.小盾牌 4.魔力药水 5.幸运石 6.什么也不带\n");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: p->gold += 100; printf("获得100金币！\n"); break;
        case 2: p->atk += 3; printf("攻击力+3！\n"); break;
        case 3: add_stats(p, 20, 0, 0, 0); printf("生命+20！\n"); break;
        case 4: add_stats(p, 0, 0, 50, 0); printf("魔力+50！\n"); break;
        case 5: p->skill += 10; printf("技能伤害+10！\n"); break;
        case 6: printf("获得成就：勇士！\n"); break;
        default: p->gold += 50; p->atk += 3; printf("随机礼物！\n");
    }
    
    return choice;
}