#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void state(int hp, int hp2, int mp, int mp2, int atk) {
 printf("你的属性：HP：%d/%d，MP%d/%d，攻击力 %d", hp2, hp, mp2, mp, atk);
};
 
int main(void)
{
	srand((unsigned)time(NULL));
 printf("   ===============================================================\n");
 printf("   =                                                             =\n");
 printf("   =                                                             =\n");
 printf("   =                   Ultra       legends      V0.1.3.2         =\n");
 printf("   =                                                             =\n");
 printf("   =                       老张stdio presents                    =\n");
 printf("   =                                                             =\n");
 printf("   ===============================================================\n\n\n\n");
 
 
 printf("剧情介绍：\n从前,Ultra大陆有一个美丽的王国，人民安居乐业，政治清明经济繁荣。\n");
 printf("直到有一天，一头恶龙来到了首都的西部荒野，它用魔法建立了一座城堡，\n并且抓走了公主，把她关在城堡的地牢里。\n");
 printf("国王忧急万分，他向全国发出了号召，哪位勇士能杀死恶龙，救出公主，就\n把公主许配给他,并在今后继承王位！\n");
  printf("可是，有一千名勇士前往了城堡，他们全都一去无回……\n");
  printf("终于，你出现了！你是全国最强大的勇士，你相信自己能成功打败恶龙，救出公主。\n");
  printf("现在，你正准备在首都做一些准备，擦亮武器，准备补给，前往城堡……\n\n\n");int h=0; printf("请选择职业：\n1.战士 血量*****  伤害*** 技能***（新手推荐！)\n2.刺客 血量***  伤害 **** 技能***\n3.剑豪  血量** 伤害*****  技能**\n4.法师  血量**  伤害*  技能******\n5.富二代  血量***  伤害** 技能**\n\n");
  scanf("%d",&h);
  int hp=500 , mp=100 , atk=60 , skill=150;/*定义主角的生命值，魔力值，基础攻击力，技能攻击力*/
    int hp2 = hp, mp2 = mp;int gold = 500;/*定义主角的当前生命值，魔力值*/
  switch (h) {
  	case 1:{
  		    //战士无需多言。。。
  		break;}
  	case 2:{
  		hp-=200,hp2-=200,atk+=10,skill+=10;//刺客
		   
  		break;}
  	case 3:{
  		hp-=250,hp2-=250,atk+=40,skill+=20;//剑豪
		    
  		break;}
  	case 4:{
	  	hp-=300,hp2-=300,atk-=20,mp+=100,mp2+=100;//法师
		  
	    break; }	
	case 5:{
		hp-=200,hp2-=200,atk-=10,mp-=50,mp2-=50,skill-=50,gold+=500;//富二代
	};break;   
	default:{printf("你的输入错误！重新选一下！");return 0;}  
  }
  
  int a=0,b=0,c = 0,d=0,e=0,f=0,g=0,k=0,m=0,n=0,criminal=0,core=0;/*定义几个形参*/
  printf("请选择一个出生礼物……\n1.一点额外的金币  2.一把小刀   3.一个小盾牌  4.一瓶增强魔力药水 5.一块幸运石 6.什么也不带\n");
  scanf("%d",&g);
  switch(g){
  	case 1:printf("你拿了一些额外的金币\n\n");gold+=100;break;
  	case 2:	printf("这把小刀是你爷爷传给你的,很钝，很生锈\n\n");atk+=3;break;
  	case 3:	printf("其实这是一块大木板，勉强能当盾牌用\n\n");hp+=20;hp2+=20;break;
  	case 4:	printf("又名莫洛托夫鸡尾酒，这种来自北境寒地的烈酒在法师中大受欢迎\n\n");mp+=50;mp2+=50;break;
  	case 5:printf("你真的不这道这是干什么的,或者真的有用？\n\n");skill+=10;break;
  	case 6:printf("真正的勇士，敢于面对困难……\n\n获得成就：勇士！\n");break;
  	default:printf("你输错了，随便给你拿一个吧\n\n");gold+=50;atk+=3;
  }
  
  do{
   printf("你现在的位置是 王国首都。\n你目前的状态是\n");
   state(hp,hp2,mp,mp2,atk);
   printf("  你现在有金币%d个,许愿之源%d个。\n你现在可以去:\n",gold,core);
  printf("1.恶龙城堡 2.武器铺 3.旅店 4.练武馆 5.医院 6.赌场 7.许愿池\n");
  scanf("%d", &c); 
  switch (c){
  case 1: /*恶龙城堡*/ {
   printf("你确定吗？前往恶龙城堡即将面临一场恶战……\n确定：1//  取消//0\n");
   scanf("%d", &a);
   if (a != 1)
   c = 5;
   break;
  };
  case 2:/*武器铺*/ {
   puts("你来到了武器铺。");
   puts("老板：欢迎光临！想要点什么？");
   printf("1.铁剑-200g 2.银剑-300g 3.金盾-200g 4.圣盾-500g 5.打劫\n");scanf("%d", &b);
   switch (b)
   {
   case 1:/*铁剑*/ {
    if (gold < 200) {
     printf("金币不足！");
     
    }
    else
    {
     puts("你装备了铁剑，攻击力+20！");
     gold -= 200;atk += 20;
    }
    break;
    ;}
   case 2:/*银剑*/{
    if (gold < 300) {
     printf("金币不足！");
 
    }
    else
    {
     puts("你装备了银剑，攻击力+40！");
     gold -= 300;atk += 40;
    }
    break;
   };
   case 3:/*金盾*/ {
    if (gold < 200) {
     printf("金币不足！");
 
    }
    else
    {
     puts("你装备了金盾，最大生命+300！");
     gold -= 200;hp += 300;hp2 += 300;
    }
    break;
    }
   case 4:/*圣盾*/ {
    if (gold < 500) {
     printf("金币不足！");
     printf("老板说：“你买不起圣盾！我都买不起!”");
 
    }
    else
    {
     puts("你装备了圣盾，最大生命+500！特殊技能的基础伤害提高了！");
     puts("获得成就：圣剑士！");
     gold -= 500;hp += 500;hp2 += 500;skill += 100;
    };
    break;
   }
   case 5:{int y=0;printf("你确定吗？\n1.确定 2.算了");scanf("%d",&y);
   if(y!=1){break;}
   else {
   	printf("你打了一下老板！\n老板生气了！\n“想打一架？老子乐意奉陪！”");
   	int hp8 = 800,atk8=100 ;/*定义敌人血量、攻击力*/
	   		  
	   		  printf("\n你观察到老板还有800点生命!\n");
	   		  do/*操作阶段*/
	   		  {
	   		   printf("轮到你行动了！\n1.普通攻击 2.特殊技能 3.休息 4.判断战局形势");
	   		   scanf("%d", &b);
	   		   switch (b) {
	   		   case 1: {hp8 -= atk;
	   		    printf("你向老板猛砍了过去！老板受到%d点伤害！老板还有%d点血量!\n", atk,hp8);
	   		    
	   		    break;
	   		   };
	   		   case 2: {//hp3 -= skill,mp2-=skill*0.75;废案
	   		     if (mp2>0)
	   		     	{
	   				 hp8 -= skill,mp2-=50;
	   				 switch (h) {
	   				 	case 1:
	   				 		 printf("你对老板使用了技能：十字斩！老板受到%d点伤害！老板还有%d点血量!你还剩%d点能量！\n", skill,hp8,mp2);
	   				 		break;
	   				 	case 2:
	   				 		 printf("你对老板使用了技能：暗影突袭！老板受到%d点伤害！老板还有%d点血量!你还剩%d点能量！\n", skill,hp8,mp2);
	   				 		break;
	   				 	case 3:
	   				 		 printf("你对老板使用了技能：万剑之战！老板受到%d点伤害！老板还有%d点血量!你还剩%d点能量！\n", skill,hp8,mp2);
	   				 		break;
	   				 	case 4:
	   				 		 printf("你对老板使用了技能：魔法光波！老板受到%d点伤害！老板还有%d点血量!你还剩%d点能量！\n", skill,hp8,mp2);
	   					 	break;
	   					case 5:	
	   					      printf("你对老板使用了技能：金钱万能！老板受到%d点伤害！老板还有%d点血量!你还剩%d点能量！\n", skill,hp8,mp2);
	   					break;
	   				 }
	   				 
	   		     	}
	   			else
	   				{
	   					printf("非法操作！你的能量耗尽了！");
	   					hp8-=0,mp2-=0;
	   				}
	   			break;
	   		   };
	   		   case 3: {
	   		    printf("你开始休息回血。你恢复了50点HP，50点MP！\n");
	   		    hp2 += 50;mp2 += 50;
	   		    if (hp2 > hp)
	   		    {
	   		     hp2 = hp;
	   		    };
	   		    if (mp2 > mp)
	   		    {
	   		     mp2 = mp;
	   		    };/*防止数值溢出*/
	   		    break;
	   		   }
	   		   case 4:state(hp, hp2, mp, mp2, atk);printf("\n山贼还有%d点血量",hp8);
	   		   };
	   		   hp2 -= atk8;
	   		   printf("老板打了一下！对你造成了%d点伤害！你还剩%d点血量！", atk8,hp2);
	   		   if (hp2 <= 0) {
	   		    printf("\n\n你被杀死了!你死了！");
	   		    printf("游戏结束。请按ENTER键退出。");
	   		    return 0;
	   		 
	   		    
	   		   };
	   		     
	   		  } while (hp8 > 0);
	   		  printf("\n你杀死了老板！拿走了所有的装备和钱！你杀人了！这是犯法的！你会后悔的！\n");criminal+=1;
	   		  gold+=900,atk+=90,hp+=900,hp2+=900;
   }}
}
   break;
   };
  case 3:/*旅店*/ {
   puts ("你看到旅馆里有很多人……你要找谁\n1.门旁的小童仆 2.一个神秘的人 3.旅店老板 4.漂亮的老板女儿 5.一个鬼鬼祟祟的人 6.赏金警官");scanf("%d",&f);
   switch (f){
   	case 1:{printf("小童仆说：“我每天虽然很累，但我每天都遇到各种各样的有趣的人，比如那个神秘的人，对了，告诉你我的梦想：我也想像你一样周游世界！等我攒够了钱我一定要去！\n你笑了笑，并没有说什么");break;} 
   case 2:{
   printf("你看到旅馆里有个披着斗篷的神秘的人，，你不能看清他的脸，你走进时那人露出了诡异的笑容，“喂，年轻人，现在我渴了，给你2金币，帮我买瓶麦芽酒！”\n");
   gold+=2;
   printf("你从酒馆老板中买到了麦芽酒！当你把酒递给他时，他笑道：“不错不错，再给你两个金币，就算是奖励了！”\n");
   printf("我们以后会再见面的！年轻人！\n");
   printf("这可真是一个奇怪的人,你想到，白给别人钱？好像没那么简单...\n");
   printf("你打算干什么？\n5//质问他在干什么\n6//向他道谢并离开\n");
   scanf("%d",&d);
   if (d!=6)
   {
   	printf("那神秘人转过头，他的脸旁十分苍老，他笑笑对你说：“不要害怕啊，孩子。希望你在战胜恶龙时，能一往无前”说罢便化作黑影消失了，你有一种奇怪的感觉，然后消失了\n");
   }
   else
    {
	printf("那神秘人说：“哈哈,没想到你还这么有礼貌，我赠与你一个祝福......”你感觉你的力量在增强！\n");
	}
   
   	atk+=5;

      break;}
    case 3:{printf("老板谈论着关于自己的旅店经常有扒手的问题...并问你是否愿意想当酒馆的保安，\n你礼貌地回绝了他，毕竟一个王国的兴衰都在你手上！");break;} 
    case 4:{printf("你和老板的女儿聊的很愉快，老板女儿说她经常希望自己能嫁给邻国的一位英俊的年轻骑士，并且很厌恶自己的爸爸总是限制自己的自由");break;}  
    case 5:{printf("那个人哆哆嗦嗦地看向你，你感觉不对劲\n");
    printf("你打算干什么？\n");
    printf("1.抓住他，问他怎么回事   2.置之不理\n");
	scanf("%d",&e);
	if (e!=2)
	{
		printf("那人哆哆嗦嗦地说：“龙……神龙…降临，诅咒……血洗大地”他应该是吓疯了，你看到他的衣领上别着一枚金狮子徽章，原来他是皇家护卫队的人！\n");
		printf("但你多年的经验告诉你,皇家护卫队的选拔十分严格，心理脆弱的人绝不会被选进的……你说出了皇家护卫队的誓词\n");
		printf("只见他笑道：“且随我来”你跟着他来到了一处角落\n");
		printf("他笑道，我和你很像，年轻人……\n你不解地望着他\n“屠龙者最后又变成了龙……我杀了这条龙的爸爸……”\n");
		printf("他撸起袖子，只见他的胳膊上布满了黑色的龙鳞！\n“我别无选择，只能装疯卖傻活着了，若回到王国，等待我的也是死路一条，哎！”\n");
		printf("你震惊了！不知如何去做，最后他告诉你只有强大的黑龙血才能治疗这病……你决计要帮助这位可怜的人，同时也要帮助自己！\n“谢谢你年轻人！带上这把黑曜石匕首！希望这对你有用！”");
		atk+=5;
	}
	else{
		printf("你独自走了……\n");
		printf("但你总感觉不对劲……");
	};break;
	}
    case 6:{printf("警官笑道：“小伙子，缺钱不？给你个任务！”\n你是否要接受任务？\n3.接受\n4.不接受");
    scanf("%d",&m);
	if(m!=4){
		printf("警长笑了：“最近有一伙山贼常常在周边的镇子里捣乱，你去肃清他们吧！”\n那伙小贼你根本就没放在眼里，你出发了并找到了山贼！");
		printf("你来到了山寨，你见到了山贼！你抽出长剑，开始了战斗！\n");
		  printf("山贼道：“今天又来个找死的！干掉他兄弟们！！！”");
		  int hp4 = 400,atk4=20 ;/*定义敌人血量、攻击力*/
		  
		  printf("\n你观察到山贼还有400点生命!\n");
		  do/*操作阶段*/
		  {
		   printf("轮到你行动了！\n1.普通攻击 2.特殊技能 3.休息 4.判断战局形势");
		   scanf("%d", &b);
		   switch (b) {
		   case 1: {hp4 -= atk;
		    printf("你向山贼猛砍了过去！山贼受到%d点伤害！山贼还有%d点血量!\n", atk,hp4);
		    
		    break;
		   };
		   case 2: {//hp3 -= skill,mp2-=skill*0.75;废案
		     if (mp2>0)
		     	{
				 hp4 -= skill,mp2-=50;
				 switch (h) {
				 	case 1:
				 		 printf("你对山贼使用了技能：十字斩！山贼受到%d点伤害！山贼还有%d点血量!你还剩%d点能量！\n", skill,hp4,mp2);
				 		break;
				 	case 2:
				 		 printf("你对山贼使用了技能：暗影突袭！山贼受到%d点伤害！山贼还有%d点血量!你还剩%d点能量！\n", skill,hp4,mp2);
				 		break;
				 	case 3:
				 		 printf("你对山贼使用了技能：万剑之战！山贼受到%d点伤害！山贼还有%d点血量!你还剩%d点能量！\n", skill,hp4,mp2);
				 		break;
				 	case 4:
				 		 printf("你对山贼使用了技能：魔法光波！山贼受到%d点伤害！山贼还有%d点血量!你还剩%d点能量！\n", skill,hp4,mp2);
					 	break;
					case 5:	
					      printf("你对山贼使用了技能：金钱万能！山贼受到%d点伤害！山贼还有%d点血量!你还剩%d点能量！\n", skill,hp4,mp2);
					break;
				 }
				 
		     	}
			else
				{
					printf("非法操作！你的能量耗尽了！");
					hp4-=0,mp2-=0;
				}
			break;
		   };
		   case 3: {
		    printf("你开始休息回血。你恢复了50点HP，50点MP！\n");
		    hp2 += 50;mp2 += 50;
		    if (hp2 > hp)
		    {
		     hp2 = hp;
		    };
		    if (mp2 > mp)
		    {
		     mp2 = mp;
		    };/*防止数值溢出*/
		    break;
		   }
		   case 4:state(hp, hp2, mp, mp2, atk);printf("\n山贼还有%d点血量",hp4);
		   };
		   hp2 -= atk4;
		   printf("轮到山贼行动了！山贼戳刺着他的匕首！对你造成了%d点伤害！你还剩%d点血量！", atk4,hp2);
		   if (hp2 <= 0) {
		    printf("\n\n你被杀死了!你死了！你被山贼打败了！这都打不过，赶紧重开吧！");
		    printf("游戏结束。请按ENTER键退出。");scanf("%d", &a);
		    return 0;
		 
		    
		   };
		     
		  } while (hp4 > 0);
		  printf("\n山贼被你消灭了！你击败了山贼！你带着山贼的头巾来见警长，警长会心地笑了：“你做得很好！年轻人！这是你的奖励！\n获得金币100！许愿之源一个！（也许许愿时能用上？）");
		  gold+=100,core+=1;
	}
	
	}
	
	  
  };break;
  }
  case 4:/*练武馆*/ {
   puts("你要找谁？\n1.圣骑士-70g 2.狂战士-100g 3.法师-50g 4.离开");scanf("%d", &b);
   switch (b) {
   case 1: {
    if (gold < 70) {
     printf("金币不足！");
     printf("圣骑士严肃地说：“年轻人，你一定要遵守骑士规范啊。”");
 
    }
    else
    {
     puts("特殊技能的基础伤害提高了！你的抗性提升了！");
     gold -= 70;skill += 50;hp+=20;hp2+=20;
     printf("圣骑士说：“你的进步让我欣慰！愿你能打败恶龙！”");
    };
    break;
   }
   case 2: {
    if (gold < 100) {
     printf("金币不足！");
     printf("狂战士轻蔑地说到：“穷鬼，学技能得要钱！”");
 
    }
    else
    {
     puts("你的攻击基础伤害提高了！最大生命值提升了！");
     gold -= 100;atk += 20;hp+=50;hp2+=50;
      printf("狂战士说：“你的进步让我欣慰！打架别给我丢脸！”");
    };
    break;
   }
   case 3: {
    if (gold < 50) {
     printf("金币不足！");
     printf("法师叹道：“我身为法师，也要养家糊口啊，这些钱不够！”");
 
    }
    else
    {
     puts("你的法力值上升了！");
     gold -= 50;mp += 50;mp2 += 50;
      printf("法师说：“你的进步让我欣慰！愿你能更好地使用你的魔法！”");
    };
    break;}
   case 4:break;
   default: {printf("你的输入错误！");break;}
   
   };
   
  };break;
  case 5:/*医院*/{printf("50金币治愈所有伤痛！恢复所有能量！\n1.治疗\n2.算了");
  scanf("%d",&n);
  if(n!=2){
  	hp2 += 9999;mp2 += 9999,gold-=50;
	      if (hp2 > hp)
	      {
	       hp2 = hp;
	      };
	      if (mp2 > mp)
	      {
	       mp2 = mp;
  }
  };

  };break;
  case 6:/*赌场*/{int guess,deal;
  srand((unsigned)time(NULL));
  int magic=rand()%100+1;
  int counter=0;
  	printf("欢迎来到小拉斯加！这里的赌局是猜数字！五次以内有不同的奖金！五次之外就输钱！\n你打算下注多少？");scanf("%d",&deal);gold-=deal;

	        
	               do{   printf("猜一个数字:‘‘");
	                scanf("%d",&guess);
	               counter++;
	              if(guess>magic)
	              printf("猜大了！\n");
	              else
	  
	                  if(guess<magic)
	                      printf("猜小了!\n");
	                   else
	                  printf("猜对了!\n") ;
	  
	      }while(guess!=magic);
	          printf("你一共猜了%d次\n",counter);
	          switch(counter)
	          {
	              case 1:printf("天命之子\n");gold+=deal*5;break;
	              case 2:printf("运气爆棚,去买彩票吧\n");gold+=deal*3;break;
	              case 3:printf("不错不错\n");gold+=deal*2.5;break;
	              case 4:printf("运气稍微好一点\n");gold+=deal*1.5;break;
	              case 5:printf("正常水平\n");gold+=deal*1.25;break;
	              default:printf("你输了！回家再练个几年吧！\n");
	          }
	          if (gold<0){printf("你欠了一屁股债！你被暴打了一顿并扔出了赌场！");hp2-=50;}
	      
  };break;
  case 7:/*许愿池抽卡*/{
  puts("你来到了城市中央的许愿池中，池水很清澈，并且还发着金色的光芒，据说这是圣泉，也许祈愿真有奇效？");
 printf("你打算许愿吗？\n1:单抽一发试试看2:爷要十连抽！3:算了，我是非洲人……\n");
 scanf("%d",&k);
 if(core<1)
 {
 	printf("你还没有许愿之源哦！去找警官做任务获得吧！");break;
 }
 else{
 switch(k){
 	case 1:{printf("在你投下许愿之源的一刻，池水散发着五颜六色的光芒……然后");
 	core-=1;
	 srand((unsigned)time(NULL));
	 if (rand()%1001-70<0)//gold
	 {
	 	printf("神非常积极地回应了你的呼唤！你抽到了当期UP武器名为雉草之道光！注意这不是梗！");
	 	hp+=300,hp2+=300,atk+=100;
	 }
	 else
	 {
	 if(rand()%1001-190<0)	
	 {printf("神认真地回应了你的呼唤，你得到了");  
	 srand((unsigned)time(NULL));
	 	int chara=rand()%10+1;
	 	if (1 == chara)
		  {
		   printf("★☆★☆★长剑名为火焰之剑\n");
		  }
		  else if (2 == chara)
		  {
		   printf("★☆★☆★长剑名为冰霜之剑\n");
		  }
		  else if (3 == chara)
		  {
		   printf("★☆★☆★剧毒匕首名为这把刀可是涂了毒的\n");
		  }
		  else if (4 == chara)
		  {
		   printf("★☆★☆★长剑名为屠龙剑\n");
		  }
		  else if (5 == chara)
		  {
		   printf("★☆★☆★战锤名为粉碎者\n");
		  }
		  else if (6 == chara)
		  {
		   printf("★☆★☆★战斧名为撕裂者\n");
		  }
		  else if (7 == chara )
		  {
		   printf("★☆★☆权杖名为安德门徒\n");
		  }
		  else if (8 == chara)
		  {
		   printf("★☆★☆★一把魔法竖琴？\n");
		  }
		  else if (9 == chara)
		  {
		   printf("★☆★☆战锤名为食人魔\n");
		  }
		  else if (10 == chara)
		  {
		   printf("★☆★☆阔剑名为复仇之刃\n");
		  }
	 	//sliver
	 	hp+=150,hp2+=150,atk+=70;
	 }
	 else
	 {
	 	if(rand()%1001-500<0)
	 	{
		 	printf("神潦草地回应了你，给了你一把还算凑合的斧子\n");
		 	hp+=50,hp2+=50,atk+=30;
		 }
		 else{
		 	printf("神没搭理你\n");
		 }
	 }
	 }
	 
	 break;}
 	case 2:{
	 	if(core<10)
	 	{
		 	printf("还没有攒够十个许愿之源哦！去找警官做任务获得吧！");break;
		 }
		 else
		{
			 printf("你直接往池水里扔了十个许愿之源，池水散发着更强的五颜六色的光芒，还是大力出奇迹啊 少年！\n\n");
				 {
				 	srand((unsigned)time(NULL));
				 	for(int i=0;i<10;i++)
					 {
					 	core-=1;
						 	 if (rand()%1001-70<0)//gold
						 	 {
						 	 	printf("神非常积极地回应了你的呼唤！你抽到了当期UP武器名为雉草之道光！注意这不是梗！\n");
						 	 	hp+=100,hp2+=100,atk+=50;
						 	 }
						 	 else
						  {
						 	 if(rand()%1001-190<0)	
						 	 {printf("神认真地回应了你的呼唤，你得到了\n"); 
							  srand((unsigned)time(NULL));
							  int chara=rand()%10+1;
						 	 	if (1 == chara)
						 		  {
						 		   printf("★☆★☆★长剑名为火焰之剑\n");
						 		  }
						 		  else if (2 == chara)
						 		  {
						 		   printf("★☆★☆★长剑名为冰霜之剑\n");
						 		  }
						 		  else if (3 == chara)
						 		  {
						 		   printf("★☆★☆★剧毒匕首名为这把刀可是涂了毒的\n");
						 		  }
						 		  else if (4 == chara)
						 		  {
						 		   printf("★☆★☆★长剑名为屠龙剑\n");
						 		  }
						 		  else if (5 == chara)
						 		  {
						 		   printf("★☆★☆★战锤名为粉碎者\n");
						 		  }
						 		  else if (6 == chara)
						 		  {
						 		   printf("★☆★☆★战斧名为撕裂者\n");
						 		  }
						 		  else if (7 == chara )
						 		  {
						 		   printf("★☆★☆权杖名为安德门徒\n");
						 		  }
						 		  else if (8 == chara)
						 		  {
						 		   printf("★☆★☆★一把魔法竖琴？\n");
						 		  }
						 		  else if (9 == chara)
						 		  {
						 		   printf("★☆★☆战锤名为食人魔\n");
						 		  }
						 		  else if (10 == chara)
						 		  {
						 		   printf("★☆★☆阔剑名为复仇之刃\n");
						 		  }
								   hp+=50,hp2+=50,atk+=20;
								   }
						 	 	//sliver
						 	 	
						              
						 	 else
						 	 {
						 	 	if(rand()%1001-500<0)
						 	 	{
						 		 	printf("神潦草地回应了你，给了你一把还算凑合的斧子\n");
						 		 	hp+=30,hp2+=30,atk+=10;
						 		 }
						 		 else{
						 		 	printf("神没搭理你\n");
						 		 }
						 	 }
						 	 }
					
				 	} 
					 }
		}
				 	
				 	
				 };break;
				 case 3:	printf("额……不妨试试嘛，其实……爆率也没你想象的那么低（偷笑.jpg+奸笑.jpg）");break;
		}break;
	
 }
 }
  }
 
  printf("\n\n\n");
  } while (c!= 1);/*首都事件组*/
 		
  printf("你来到了恶龙城堡，你见到了恶龙！你抽出长剑，开始与巨龙恶斗！\n");
  printf("恶龙吼道：“凡人！休得谮越！”");
  int hp3 = 2500,atk3=0 ;/*定义敌人血量、攻击力*/
  for(atk3=0;atk3<50;++atk3){
  	atk3=rand()%51+50;
  }
  printf("\n你观察到恶龙还有2500点生命!\n");
  do/*操作阶段*/
  {
   printf("轮到你行动了！\n1.普通攻击 2.特殊技能 3.休息 4.判断战局形势");
   scanf("%d", &b);
   switch (b) {
   case 1: {hp3 -= atk;
    printf("你向恶龙猛砍了过去！恶龙受到%d点伤害！恶龙还有%d点血量!\n", atk,hp3);
    
    break;
   };
   case 2: {//hp3 -= skill,mp2-=skill*0.75;废案
     if (mp2>0)
     	{
		 hp3 -= skill,mp2-=50;
		 switch (h) {
		 	case 1:
		 		 printf("你对恶龙使用了技能：十字斩！恶龙受到%d点伤害！恶龙还有%d点血量!你还剩%d点能量！\n", skill,hp3,mp2);
		 		break;
		 	case 2:
		 		 printf("你对恶龙使用了技能：暗影突袭！恶龙受到%d点伤害！恶龙还有%d点血量!你还剩%d点能量！\n", skill,hp3,mp2);
		 		break;
		 	case 3:
		 		 printf("你对恶龙使用了技能：万剑之战！恶龙受到%d点伤害！恶龙还有%d点血量!你还剩%d点能量！\n", skill,hp3,mp2);
		 		break;
		 	case 4:
		 		 printf("你对恶龙使用了技能：魔法光波！恶龙受到%d点伤害！恶龙还有%d点血量!你还剩%d点能量！\n", skill,hp3,mp2);
			 	break;
			case 5:	
			      printf("你对恶龙使用了技能：金钱万能！恶龙受到%d点伤害！恶龙还有%d点血量!你还剩%d点能量！\n", skill,hp3,mp2);
			break;
		 }
		 
     	}
	else
		{
			printf("非法操作！你的能量耗尽了！");
			hp3-=0,mp2-=0;
		}
	break;
   };
   case 3: {
    printf("你开始休息回血。你恢复了50点HP，50点MP！\n");
    hp2 += 50;mp2 += 50;
    if (hp2 > hp)
    {
     hp2 = hp;
    };
    if (mp2 > mp)
    {
     mp2 = mp;
    };/*防止数值溢出*/
    break;
   }
   case 4:state(hp, hp2, mp, mp2, atk);printf("\n恶龙还有%d点血量",hp3);
   };
   hp2 -= atk3;
   printf("轮到恶龙行动了！恶龙呼吸烈焰！对你造成了%d点伤害！你还剩%d点血量！", atk3,hp2);
   if (hp2 <= 0) {
    printf("\n\n你被烧成了一撮灰!你死了！你被恶龙打败了！这都打不过，赶紧重开吧！");
    printf("游戏结束。请按ENTER键退出。");scanf("%d", &a);
    return 0;
 
    
   };
     
  }
   while (hp3 > 0);
  printf("\n恶龙的血量归零了！\n恶龙倒下了“不要以为这就打败了我，人类！这一切还没完……”\n你击败了恶龙！救出了公主！从此过上了幸福的生活！但是你发现自己的胳膊上出现了龙鳞……。\n");
  printf("你认为自己已经足够强大去开启新的冒险了！全国最好的铁匠铺为你打造好了盔甲！");hp+=500;hp2+=500;gold+=5000;
  int a1=0,b1=0,c1= 0,d1=0,e1=0,f1=0,m1=0,n1=0;
 do{
   printf("你现在的位置是 王国首都。\n你目前的状态是\n");
   state(hp,hp2,mp,mp2,atk);
   printf("  你现在有金币%d个，许愿之源%d个。\n你现在可以去:\n",gold,core);
  printf("1.圣龙所在的世界之巅 2.神级武器铺 3.旅店 4.神殿 5.医院 6.赌场 7.许愿池\n");
  scanf("%d", &c1); 
  switch (c1){
  case 1: /*恶龙城堡*/ {
   printf("你确定吗？前往世界之巅即将面临一场史诗般的战斗……\n确定：1//  取消//0\n");
   scanf("%d", &a1);
   if (a1 != 1)
   c1 = 5;
   break;
  };
  case 2:/*武器铺*/ {
   puts("你来到了武器铺。");
   puts("老板：欢迎光临！想要点什么？\n你打算干什么?");
   printf("1.誓约剑-2000g 2.日耀剑-3000g 3.抛光银盾-2500g 4.龙鳞甲-5000g 5.攻击老板\n");scanf("%d", &b1);
   switch (b1)
   {
   case 1:/*铁剑+*/ {
    if (gold < 2000) {
     printf("金币不足！");
     
    }
    else
    {
     puts("你装备了誓约剑，攻击力+200！");
     gold -= 2000;atk += 200;
    }
    break;
    ;}
   case 2:/*银剑+*/{
    if (gold < 3000) {
     printf("金币不足！");
 
    }
    else
    {
     puts("你装备了日耀剑，攻击力+400！");
     gold -= 3000;atk += 400;
    }
    break;
   };
   case 3:/*金盾+*/ {
    if (gold < 2000) {
     printf("金币不足！");
 
    }
    else
    {
     puts("你装备了抛光银盾，最大生命+1000！");
     gold -= 2500;hp += 1000;hp2 += 1000;
    }
    break;
    }
   case 4:/*圣盾+*/ {
    if (gold < 5000) {
     printf("金币不足！");
     printf("老板说：“你买不起龙鳞甲！我都买不起!”");
 
    }
    else
    {
     puts("你装备了龙鳞甲，最大生命+2000！特殊技能的基础伤害提高了！");
     puts("获得成就：圣剑士！");
     gold -= 5000;hp += 5000;hp2 += 2000;skill += 300;
    };
    break;
   }
   case 5:{int y1=0;printf("你确定吗？\n1.确定 2.算了");scanf("%d",&y1);
      if(y1!=1){break;}
	  else {printf("你打了一下老板!\n老板生气了!\n“你个人渣！”\n老板挥舞着他的战锤名为雷神之锤!\n老板打了一下你！\n一道闪电击中了你！你晕了过去！\n老板踢了一下！\n老板向你施展了一个魔法！\n你看不见了！老板打了一下！雷击了一下你！\n你死了。。。");
   return 0;}
}
   }break;
   };
  case 3:/*旅店*/ {
   puts ("你看到旅馆里有很多人……你要找谁\n1.门旁的小童仆 2.一个神秘的人 3.旅店老板 4.漂亮的老板女儿 5.一个鬼鬼祟祟的人 6.赏金警官");scanf("%d",&f1);
   switch (f1){
   	case 1:{printf("小童仆见到你慌忙下跪：“国王陛下！”\n你并没有说什么,只是觉得有点不舒服");break;} 
   case 2:{
   printf("你再次看到那个披着斗篷的神秘的人，你走进时那人向你行礼,“国王陛下,恕我年老膝盖发炎不能向您下跪”\n");
   printf("你对他的帮助表示十分感谢“这算什么，尊敬的国王！麻烦的事情还在后面”\n");
   printf("你杀死了那条龙，龙族都有着强大的诅咒，屠龙者会变成龙……\n");
   printf("好像事情的一切远远没那么简单...\n");
   printf("你打算干什么？\n5//问他还有没有更好的方法\n6//向他道谢并离开\n");
   scanf("%d",&d1);
   if (d1!=6)
   {
   	printf("那神秘人转过头，他的脸旁十分苍老，他笑笑对你说：“不要害怕啊，国王，听从你内心的声音”说罢便化作黑影消失了，你有一种奇怪的感觉，然后消失了\n");
   }
   else
    {
	printf("那神秘人说：“愿陛下武德昌盛，战无不胜！”说罢，便化成一缕青烟消失了\n");
	}
   

      break;}
    case 3:{printf("老板向你诉苦，因为税务要把他压垮了");break;} 
    case 4:{printf("你和老板的女儿聊的很愉快，你为老板女儿给那位骑士写了一封信，老板的女儿很感激你");break;}  
    case 5:{printf("那个人哆哆嗦嗦地看向你，你感觉不对劲\n");
    printf("你打算干什么？\n");
    printf("1.抓住他，问他怎么回事   2.置之不理\n");
	scanf("%d",&e1);
	if (e1!=2)
	{
		printf("那人哆哆嗦嗦地说：“龙……神龙…降临，诅咒……血洗大地”你知道他在装疯\n");
		printf("你喝令随从退下\n");
		printf("只见他笑道：“且随我来”你跟着他来到了一处角落\n");
		printf("他笑道，你还记得当时的约定嘛，国王陛下？\n你告诉他你没有忘记\n");
		printf("“希望你能帮帮我！”\n");
		printf("你震惊了！不知如何去做，最后他告诉你只有强大的圣龙龙血才能治疗这病……你发誓要为你们找到解药\n“谢谢国王！”");
	}
	else{
		printf("你独自走了……\n");
		printf("但你总感觉不对劲……");
	};break;
	}
    case 6:{printf("市长道：“陛下，请帮帮我们！”\n你是否要接受任务？\n3.接受\n4.不接受");
    scanf("%d",&m1);
	if(m1!=4){
		printf("市长说：“最近有一伙江洋大盗常常在周边的镇子里捣乱，麻烦陛下肃清他们！”\n那伙小贼你根本就没放在眼里，你出发了并找到了江洋大盗！");
		printf("你来到了山寨，你见到了江洋大盗！你抽出长剑，开始了战斗！\n");
		  printf("江洋大盗道：“国王陛下，我劝你三思。。。”\n你更加生气了！");
		  int hp6 = 2000,atk6=80 ;/*定义敌人血量、攻击力*/
		  
		  printf("\n你观察到江洋大盗还有2000点生命!\n");
		  do/*操作阶段*/
		  {
		   printf("轮到你行动了！\n1.普通攻击 2.特殊技能 3.休息 4.判断战局形势");
		   scanf("%d", &b1);
		   switch (b1) {
		   case 1: {hp6-= atk;
		    printf("你向江洋大盗猛砍了过去！江洋大盗受到%d点伤害！江洋大盗还有%d点血量!\n", atk,hp6);
		    
		    break;
		   };
		   case 2: {//hp3 -= skill,mp2-=skill*0.75;废案
		     if (mp2>0)
		     	{
				 hp6 -= skill,mp2-=50;
				 switch (h) {
				 	case 1:
				 		 printf("你对江洋大盗使用了技能：十字斩！江洋大盗受到%d点伤害！江洋大盗还有%d点血量!你还剩%d点能量！\n", skill,hp6,mp2);
				 		break;
				 	case 2:
				 		 printf("你对江洋大盗使用了技能：暗影突袭！江洋大盗受到%d点伤害！江洋大盗还有%d点血量!你还剩%d点能量！\n", skill,hp6,mp2);
				 		break;
				 	case 3:
				 		 printf("你对江洋大盗使用了技能：万剑之战！江洋大盗受到%d点伤害！江洋大盗还有%d点血量!你还剩%d点能量！\n", skill,hp6,mp2);
				 		break;
				 	case 4:
				 		 printf("你对江洋大盗使用了技能：魔法光波！江洋大盗受到%d点伤害！江洋大盗还有%d点血量!你还剩%d点能量！\n", skill,hp6,mp2);
					 	break;
					case 5:	
					      printf("你对江洋大盗使用了技能：金钱万能！江洋大盗受到%d点伤害！江洋大盗还有%d点血量!你还剩%d点能量！\n", skill,hp6,mp2);
					break;
				 }
				 
		     	}
			else
				{
					printf("非法操作！你的能量耗尽了！");
					hp6-=0,mp2-=0;
				}
			break;
		   };
		   case 3: {
		    printf("你开始休息回血。你恢复了50点HP，50点MP！\n");
		    hp2 += 50;mp2 += 50;
		    if (hp2 > hp)
		    {
		     hp2 = hp;
		    };
		    if (mp2 > mp)
		    {
		     mp2 = mp;
		    };/*防止数值溢出*/
		    break;
		   }
		   case 4:state(hp, hp2, mp, mp2, atk);printf("\n江洋大盗还有%d点血量",hp6);
		   };
		   hp2 -= atk6;
		   printf("轮到江洋大盗行动了！江洋大盗挥舞着他的阔剑！对你造成了%d点伤害！你还剩%d点血量！", atk6,hp2);
		   if (hp2 <= 0) {
		    printf("\n\n你被杀死了!你死了！你被江洋大盗打败了！猥琐发育，别浪");
		    printf("游戏结束。请按ENTER键退出。");scanf("%d", &a1);
		    return 0;
		 
		    
		   };
		     
		  } while (hp6 > 0);
		  printf("\n江洋大盗被你消灭了！\n“呵呵，国王，你不知你干了什么...”你击败了江洋大盗！你带着江洋大盗的剑来见市长.“多谢陛下！这是卑职的一点表示...”\n");
		  gold+=1000,core+=2;
	}
	
	}
	
	  
  };break;
  }
  case 4:/*练武馆*/ {int donate;
   
   if (criminal!=0){printf("你的罪行触怒了众神！他们拒绝你进入神殿！");}
   else{puts("你要供奉那座神像？\n1.圣骑士之神奥古斯丁-350g 2.狂战士之神索尔-500g 3.法师之神梅林-250g 4.离开5.和神庙女祭司交谈");scanf("%d", &b1);
   switch (b1) {
   case 1: {
    if (gold < 350) {
     printf("金币不足！");
     printf("圣骑士之神严肃地说：“凡人，汝甚傲慢！”\n");
     printf("汝需重新修习！");
     printf("你感觉自己变得虚弱了！");atk-=10;
    }
    else
    {
     puts("特殊技能的基础伤害提高了！你的抗性提升了！");
     gold -= 350;skill += 150;hp+=200;hp2+=200;
     printf("圣骑士之神说：“汝之进步令我欣慰！愿你能保持本心！”");
    };
    break;
   }
   case 2: {
    if (gold < 500) {
     printf("金币不足！");
     printf("狂战士之神索尔低语：“汝触怒了吾”");
     printf("一道闪电从天而降！");
     printf("这电到了你！");hp2-=100;
    }
    else
    {
     puts("你的攻击基础伤害提高了！最大生命值提升了！");
     gold -= 500;atk += 150;hp+=300;hp2+=300;
      printf("狂战士之神索尔说：“你的进步让我欣慰！打架别给我丢脸！”");
    };
    break;
   }
   case 3: {
    if (gold < 250) {
     printf("金币不足！");
     printf("法师之神梅林叹道：“汝迷失了道路，凡人，恕吾不能帮你”");
     printf("你感觉变得无知了！");skill-=10;
 
    }
    else
    {
     puts("你的法力值上升了！");
     gold -= 250;mp += 150;mp2 += 150;
      printf("法师说：“你的进步让我欣慰！愿你能更好地使用你的魔法！”");
    };
    break;}
   case 4:break;
   case 5:{printf("神庙的女祭司请你为神庙捐点钱...\n你打算捐多少?");scanf("%d",&donate);
   
    if (donate>gold){donate=gold;printf("你把所有钱全都给了女祭司");}
    if(donate >=1000){printf("你的慷慨深深地令我佩服，我赠与你一个祝福");gold-=donate;atk+=500;hp+=500;hp2+=500;mp+=100;mp2+=100;}
    else if(donate<1000&&donate>500){
      printf("感谢你所做的贡献");gold-=donate;atk+=300;hp+=200,hp2+=200;}
      else if (donate<=500&&donate>100){
        printf("你是一个虔诚的人");gold-=donate;hp+=150;hp2+=150;
      }
      else {printf("小气鬼");gold-=donate;}
    };break;
   }
   //default: {printf("你的输入错误！");break;}
   
   }};
   break;
  case 5:/*医院*/{printf("150金币治愈所有伤痛！恢复所有能量！\n1.治疗\n2.算了");
  scanf("%d",&n1);
  if(n1!=2){
  	hp2 += 9999;mp2 += 9999,gold-=150;
	      if (hp2 > hp)
	      {
	       hp2 = hp;
	      };
	      if (mp2 > mp)
	      {
	       mp2 = mp;
  }
  };

  };break;
  case 6:/*赌场*/{int guess1,deal1;
    srand((unsigned)time(NULL));
    int magic1=rand()%100+1;
    int counter1=0;
    	printf("欢迎来到小拉斯加！这里的赌局是猜数字！五次以内有不同的奖金！五次之外就输钱！\n你打算下注多少？");scanf("%d",&deal1);gold-=deal1;
  
  	        
  	               do{   printf("猜一个数字:‘‘");
  	                scanf("%d",&guess1);
  	               counter1++;
  	              if(guess1>magic1)
  	              printf("猜大了！\n");
  	              else
  	  
  	                  if(guess1<magic1)
  	                      printf("猜小了!\n");
  	                   else
  	                  printf("猜对了!\n") ;
  	  
  	      }while(guess1!=magic1);
  	          printf("你一共猜了%d次\n",counter1);
  	          switch(counter1)
  	          {
  	              case 1:printf("天命之子\n");gold+=deal1*5;break;
  	              case 2:printf("运气爆棚,去买彩票吧\n");gold+=deal1*3;break;
  	              case 3:printf("不错不错\n");gold+=deal1*2.5;break;
  	              case 4:printf("运气稍微好一点\n");gold+=deal1*1.5;break;
  	              case 5:printf("正常水平\n");gold+=deal1*1.25;break;
  	              default:printf("你输了！回家再练个几年吧！\n");
  	          }
  	          if (gold<0){printf("你欠了一屁股债！你被暴打了一顿并扔出了赌场！");hp2-=50;}
  	      
    };break;
      case 7:/*许愿池抽卡*/{
	  puts("你来到了城市中央的许愿池中，池水很清澈，并且还发着金色的光芒，据说这是圣泉，也许祈愿真有奇效？");
	 printf("你打算许愿吗？\n1:单抽一发试试看2:爷要十连抽！3:算了，我是非洲人……\n");
	 scanf("%d",&k);
	 if(core<1)
	 {
	 	printf("你还没有许愿之源哦！去找警官做任务获得吧！");break;
	 }
	 else{
	 switch(k){
	 	case 1:{printf("在你投下许愿之源的一刻，池水散发着五颜六色的光芒……然后");
		 core-=1;
		 srand((unsigned)time(NULL));
		 if (rand()%1001-70<0)//gold
		 {
		 	printf("神非常积极地回应了你的呼唤！你抽到了当期UP武器名为雉草之道光！注意这不是梗！");
		 	hp+=300,hp2+=300,atk+=100;
		 }
		 else
		 {
		 if(rand()%1001-190<0)	
		 {printf("神认真地回应了你的呼唤，你得到了");  
		 srand((unsigned)time(NULL));
		 	int chara=rand()%10+1;
		 	if (1 == chara)
			  {
			   printf("★☆★☆★长剑名为火焰之剑\n");
			  }
			  else if (2 == chara)
			  {
			   printf("★☆★☆★长剑名为冰霜之剑\n");
			  }
			  else if (3 == chara)
			  {
			   printf("★☆★☆★剧毒匕首名为这把刀可是涂了毒的\n");
			  }
			  else if (4 == chara)
			  {
			   printf("★☆★☆★长剑名为屠龙剑\n");
			  }
			  else if (5 == chara)
			  {
			   printf("★☆★☆★战锤名为粉碎者\n");
			  }
			  else if (6 == chara)
			  {
			   printf("★☆★☆★战斧名为撕裂者\n");
			  }
			  else if (7 == chara )
			  {
			   printf("★☆★☆权杖名为安德门徒\n");
			  }
			  else if (8 == chara)
			  {
			   printf("★☆★☆★一把魔法竖琴？\n");
			  }
			  else if (9 == chara)
			  {
			   printf("★☆★☆战锤名为食人魔\n");
			  }
			  else if (10 == chara)
			  {
			   printf("★☆★☆阔剑名为复仇之刃\n");
			  }
		 	//sliver
		 	hp+=150,hp2+=150,atk+=70;
		 }
		 else
		 {
		 	if(rand()%1001-500<0)
		 	{
			 	printf("神潦草地回应了你，给了你一把还算凑合的斧子\n");
			 	hp+=50,hp2+=50,atk+=30;
			 }
			 else{
			 	printf("神没搭理你\n");
			 }
		 }
		 }
		 
		 break;}
	 	case 2:{
		 	if(core<10)
		 	{
			 	printf("还没有攒够十个许愿之源哦！去找警官做任务获得吧！");break;
			 }
			 else
			{
				 printf("你直接往池水里扔了十个许愿之源，池水散发着更强的五颜六色的光芒，还是大力出奇迹啊 少年！\n\n");
					 {
					 	srand((unsigned)time(NULL));
					 	for(int i=0;i<10;i++)
						 {
						 	core-=1;
							 	 if (rand()%1001-70<0)//gold
							 	 {
							 	 	printf("神非常积极地回应了你的呼唤！你抽到了当期UP武器名为雉草之道光！注意这不是梗！\n");
							 	 	hp+=100,hp2+=100,atk+=50;
							 	 }
							 	 else
							  {
							 	 if(rand()%1001-190<0)	
							 	 {printf("神认真地回应了你的呼唤，你得到了\n"); 
								  srand((unsigned)time(NULL));
								  int chara=rand()%10+1;
							 	 	if (1 == chara)
							 		  {
							 		   printf("★☆★☆★长剑名为火焰之剑\n");
							 		  }
							 		  else if (2 == chara)
							 		  {
							 		   printf("★☆★☆★长剑名为冰霜之剑\n");
							 		  }
							 		  else if (3 == chara)
							 		  {
							 		   printf("★☆★☆★剧毒匕首名为这把刀可是涂了毒的\n");
							 		  }
							 		  else if (4 == chara)
							 		  {
							 		   printf("★☆★☆★长剑名为屠龙剑\n");
							 		  }
							 		  else if (5 == chara)
							 		  {
							 		   printf("★☆★☆★战锤名为粉碎者\n");
							 		  }
							 		  else if (6 == chara)
							 		  {
							 		   printf("★☆★☆★战斧名为撕裂者\n");
							 		  }
							 		  else if (7 == chara )
							 		  {
							 		   printf("★☆★☆权杖名为安德门徒\n");
							 		  }
							 		  else if (8 == chara)
							 		  {
							 		   printf("★☆★☆★一把魔法竖琴？\n");
							 		  }
							 		  else if (9 == chara)
							 		  {
							 		   printf("★☆★☆战锤名为食人魔\n");
							 		  }
							 		  else if (10 == chara)
							 		  {
							 		   printf("★☆★☆阔剑名为复仇之刃\n");
							 		  }
									   hp+=50,hp2+=50,atk+=20;
									   }
							 	 	//sliver
							 	 	
							              
							 	 else
							 	 {
							 	 	if(rand()%1001-500<0)
							 	 	{
							 		 	printf("神潦草地回应了你，给了你一把还算凑合的斧子\n");
							 		 	hp+=30,hp2+=30,atk+=10;
							 		 }
							 		 else{
							 		 	printf("神没搭理你\n");
							 		 }
							 	 }
							 	 }
						
					 	} 
						 }
			}
					 	
					 	
					 };break;
					 case 3:	printf("额……不妨试试嘛，其实……爆率也没你想象的那么低（偷笑.jpg+奸笑.jpg）");break;
			}break;
		
	 }
	 }
  }
 
  printf("\n\n\n");
  } while (c1 != 1);/*首都事件组*/
 		
  printf("你来到了世界之巅，你见到了圣龙！你抽出长剑，开始与巨龙恶斗！\n");
  printf("圣龙吼道：“凡人！汝贪得无厌，必受天谴！”");
  int hp5 = 20000,atk5=0 ;/*定义敌人血量、攻击力*/
  for(atk5=0;atk5<50;++atk5){
  	atk5=rand()%521+50;
  }
  printf("\n你观察到圣龙还有20000点生命!\n");
do/*操作阶段*/
  {
   printf("轮到你行动了！\n1.普通攻击 2.特殊技能 3.休息 4.判断战局形势");
   scanf("%d", &b1);
   switch (b1) {
   case 1: {hp5 -= atk;
    printf("你向圣龙猛砍了过去！圣龙受到%d点伤害！圣龙还有%d点血量!\n", atk,hp5);
    
    break;
   };
   case 2: {//hp3 -= skill,mp2-=skill*0.75;废案
     if (mp2>0)
     	{
		 hp5 -= skill,mp2-=100;
		 switch (h) {
		 	case 1:
		 		 printf("你对圣龙使用了技能：十字斩！圣龙受到%d点伤害！圣龙还有%d点血量!你还剩%d点能量！\n", skill,hp5,mp2);
		 		break;
		 	case 2:
		 		 printf("你对圣龙使用了技能：暗影突袭！圣龙受到%d点伤害！圣龙还有%d点血量!你还剩%d点能量！\n", skill,hp5,mp2);
		 		break;
		 	case 3:
		 		 printf("你对圣龙使用了技能：万剑之战！圣龙受到%d点伤害！圣龙还有%d点血量!你还剩%d点能量！\n", skill,hp5,mp2);
		 		break;
		 	case 4:
		 		 printf("你对圣龙使用了技能：魔法光波！圣龙受到%d点伤害！圣龙还有%d点血量!你还剩%d点能量！\n", skill,hp5,mp2);
			 	break;
			case 5:	
			      printf("你对圣龙使用了技能：金钱万能！圣龙受到%d点伤害！圣龙还有%d点血量!你还剩%d点能量！\n", skill,hp5,mp2);
			break;
		 }
		 
     	}
	else
		{
			printf("非法操作！你的能量耗尽了！");
			hp5-=0,mp2-=0;
		}
	break;
   };
   case 3: {
    printf("你开始休息回血。你恢复了50点HP，50点MP！\n");
    hp2 += 50;mp2 += 50;
    if (hp2 > hp)
    {
     hp2 = hp;
    };
    if (mp2 > mp)
    {
     mp2 = mp;
    };/*防止数值溢出*/
    break;
   }
   case 4:state(hp, hp2, mp, mp2, atk);printf("\n圣龙还有%d点血量",hp5);
   };
   hp2 -= atk5;
   printf("轮到恶龙行动了！圣龙发出光波！这烧伤了你！对你造成了%d点伤害！你还剩%d点血量！", atk5,hp2);
   if (hp2 <= 0) {
    printf("\n\n你被分解成了灰!你死了！你被圣龙打败了！");
    printf("游戏结束。请按ENTER键退出。");scanf("%d", &a1);
    return 0;
 }
     
}
   while (hp5 > 0);
  printf("\n圣龙的血量归零了！\n圣龙倒下了“受苦吧，人类！”\n你击败了圣龙！解除了你和那个人的诅咒，但是一切还远远没有结束\n");
  printf("也许这根本没有尽头，但是你认为这有一个结局……\n");
  printf("你总是觉得背后一定有一个真正的幕后主使，他驱动着你……驱动着你玩下去，而你想要的，仅仅是一个结束\n");
  printf("你回到都城，人民视你为英雄，他们欢呼着，但你不为所动。\n");
  printf("你发誓一定要结束这一切");
  printf("游戏结束！感谢游玩！敬请期待v1.3.0版本，新的传奇英雄和神器！。请按ENTER键退出。");scanf("%d", &a1);
 return 0;
};
