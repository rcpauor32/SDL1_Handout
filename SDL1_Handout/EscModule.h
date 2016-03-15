
class EscModule : public Module{
	bool EscPress() {
		while (!kbhit() || getchar() != 27){
			return false;
		}
		return true;
	}
};