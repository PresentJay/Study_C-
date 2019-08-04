from konlpy.tag import Kkma
from konlpy.utils import pprint
kkma = Kkma()
pprint(kkma.pos(u'한국어 분석은 재밌습니다!'))
