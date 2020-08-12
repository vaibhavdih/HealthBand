from rest_framework.urlpatterns import format_suffix_patterns
from django.conf.urls import url , include
from . import views

urlpatterns =[

    url('^data/',views.SongsView.as_view()),


]

urlpatterns = format_suffix_patterns(urlpatterns)